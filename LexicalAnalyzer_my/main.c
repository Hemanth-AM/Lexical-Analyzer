#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include "lexical.h"
#include "typdef.h"

LEXICAL lexi;//struct for lexical analysis

int main(int argc, char **argv)
{
    if (argc < 2)// to check for source file name
    {
        printf("Please provide a source file name\n");
        return failure;
    }

    if (strstr(argv[1], ".c") == NULL)// Check for .c file extension
    {
        printf(".c File is Not Found\n");
        return failure;
    }
      
    lexi.file_name = argv[1];
    lexi.fptr = fopen(lexi.file_name, "r");
    if (lexi.fptr == NULL)// Check if file pointer is NULL
    {
        printf("File open failed\n");
        return failure;
    }
    printf("Open     : %s     : success\n",lexi.file_name);
    printf("Parsing  : %s     : started\n\n",lexi.file_name);
     
    while (get_token(&lexi) == success)//to check for tokens
    {

         if (isspace(lexi.token[0]) == 0)// Check for valid token
         {
           // printf("Token : %s\n", lexi.token);

          if(check_keyword(lexi.token) == success)// to check for keywords
         {
            printf("Keyword                 : %s\n", lexi.token);
         }
         else if (check_operator(lexi.token) == success)// to check for operators
         {
            printf("Operator                : %s\n", lexi.token);
         }
         else if(check_literal(lexi.token) == success)// to check for literals
         {
            printf("Literal                 : %s\n",lexi.token);
         }
         else if(check_arr(&lexi) == success)
         {
            
         }
         else // If not a keyword, operator, or literal, it must be an identifier
         {
            printf("Identifier              : %s\n", lexi.token);
         }
        }
        
    }
            printf("\nParsing : %s      : Done\n", lexi.file_name);
     fclose(lexi.fptr);// Close the file pointer
     return success;
}
