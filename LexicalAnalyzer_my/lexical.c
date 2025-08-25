#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexical.h"
#include "typdef.h"

static const char* keywords[MAX_KEYWORDS] = {
    "int", "float", "return", "if", "else", "while", "for", "do", "break", "continue",
    "char", "double", "void", "switch", "case", "default", "const", "static", "sizeof", "struct"
};

static const char* operators = "+-*/%=!<>|&";
static const char* specialcharacters = " ,;{}()[]";

int get_token(LEXICAL *lexi) {
    unit c;

    // Skip whitespace
    do {
        c = fgetc(lexi->fptr);
        if (c == EOF) return failure;
    } while (isspace(c));// to check for whitespace

     if(c == '#') // Preprocessor directive
     {
       unit i = 0;
       while(isspace(c) == 0)// to check for non-whitespace characters
       {
           lexi->token[i] = (char)c;
           c = getc(lexi->fptr);
           i++;
       }
        lexi->token[i] = '\0'; // Null-terminate the token
        printf("Preprocessor Directive  : %s\n",lexi->token);
     }


    // Identifier or number
    if (strchr(operators, c) == NULL && strchr(specialcharacters, c) == NULL)
    {
        unit i = 0;
        while (c != EOF &&
               strchr(operators, c) == NULL &&
               strchr(specialcharacters, c) == NULL &&
               c != ' ' && c != '\n' && c != '\t') // Check for valid identifier/number characters
        {

            if(c == '"' || c == '\'')// Check for string or character literal
            {
                unit i = 0;
                 lexi->token[i++] = (char)c;
                 c = fgetc(lexi->fptr);

                while(c != '"' && c != '\'' )// Check for end of string/character literal
                {
                    lexi->token[i++] = (char)c;
                    c = fgetc(lexi->fptr);

                }
                lexi->token[i++] = (char)c;
                lexi->token[i] = '\0';
                return success;
            }
            lexi->token[i++] = (char)c;
            c = fgetc(lexi->fptr);
        }
        lexi->token[i] = '\0';
        if (c != EOF) ungetc(c, lexi->fptr);// Push back the character
        return success;
    }
    // Single-character operator or special char
    else 
    {
        lexi->token[0] = (char)c;
        lexi->token[1] = '\0';
        return success;
    }
}

/*
Description: Check if a token is a keyword
input: const char *token - the token to check
output: status - success if the token is a keyword, failure otherwise
return: status - success if the token is a keyword, failure otherwise
*/
int check_keyword(const char *token)
{
    for(int i = 0; i < MAX_KEYWORDS; i++)// Check each keyword
    {
        if(strcmp(keywords[i], token) == 0)// Compare with keyword
        {
            return success;
        }
        
    }
    return failure;
}

/*
Description: Check if a token is an operator
input: const char *token - the token to check
output: status - success if the token is an operator, failure otherwise
return: status - success if the token is an operator, failure otherwise
*/
int check_operator(const char *token)
{
    if (strchr(operators, token[0]) != NULL && token[1] == '\0')// Check for single-character operator
    {
        return success;
    }
    if (strchr(specialcharacters, token[0]) != NULL && token[1] == '\0')// Check for single-character special character
    {
        return success;
    }
    return failure;
}

/*
Description: Check if a token is a literal
input: const char *token - the token to check
output: status - success if the token is a literal, failure otherwise
return: status - success if the token is a literal, failure otherwise
*/
int check_literal(const char *token)
{
    if(token[0] == '"' || token[0] == '\'')// Check for string or character literal
    {
        return success;
    }
    int i = 0;
    while(token[i] != '\0')
    {
        if((isdigit(token[i])) || (token[i] == '.'))// Check for digit or decimal point
        {
                i++;
        }
        else
        {
           return failure;
        }
    }
    return success;
}


/*
Description: Check if a token is an array
input: LEXICAL *lexi - the lexical analyzer instance
output: status - success if the token is an array, failure otherwise
return: status - success if the token is an array, failure otherwise
*/
int check_arr(LEXICAL *lexi)
{
    char buffer[50]; // bigger buffer
    unit c = getc(lexi->fptr);
    unit i = 0;

    if (c == '[')
    {
        buffer[i++] = (char)c; // store '['
        c = getc(lexi->fptr);

        // Read until closing bracket
        while (c != ']' && c != EOF) {
            buffer[i++] = (char)c;
            c = getc(lexi->fptr);
        }

        if (c == ']') {
            buffer[i++] = ']'; // store closing bracket
        }

        buffer[i] = '\0'; // null terminate
       printf("Array                   : %s%s\n", lexi->token, buffer);
        return success;
    }

    // Not an array
    ungetc(c, lexi->fptr);
    return failure;
}
