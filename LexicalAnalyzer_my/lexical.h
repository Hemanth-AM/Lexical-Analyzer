#ifndef LEXICAL_H
#define LEXICAL_H
#include<stdio.h>

#define MAX_KEYWORDS  20
#define MAX_SIZE     100

typedef struct lex
{
   char *file_name;
   FILE *fptr;
   char token[MAX_SIZE];
   
}LEXICAL;

// Function to get the next token from the input
int get_token(LEXICAL *lexi);

// Function to check if a token is a keyword
int check_keyword(const char *token);

// Function to check if a token is an operator
int check_operator(const char *token);

// Function to check if a token is a literal (string or number)
int check_literal(const char *token);

// Function to check if a token is an array
int check_arr(LEXICAL *lexi);





#endif