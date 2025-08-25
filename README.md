# Lexical-Analyzer
Implementing minimalistic version of a Lexer given the input C program. Get a feel of compiler design
![c-project-lexical-analyser](https://github.com/user-attachments/assets/2636678f-2e8c-480d-bb60-6fb4f92e2ea7)
# Introduction
Lexical Analyzer Project in C : In computer science, lexical analysis is the process of converting a sequence of characters into a sequence of tokens. A program or function which performs lexical analysis is called a lexical analyzer, lexer, or scanner. A lexer often exists as a single function which is called by a parser or another function. Some popular tools like Lex and Yacc are examples of practical usage of lexical analysis. 

# Lexical Analyzers in Compiler Design:

Lexical analyzers are designed to recognize keywords, operators and identifiers. It can also include others like integers, floating point numbers, character strings and other similar items that are written as part of the source program. Typically, they are given names a tokens, which are parsed in the given input and match against a pre-defined rules called grammar. When the given program is not matching with this grammar, the error is provided to the user in form of compilation error. 

A token is a string of characters, categorized according to the rules as a symbol (e.g. Identifier, Number, Comma etc…). The process of forming tokens from an input stream of characters is called tokenization, and the lexer categorizes them according to a symbol type. A token can look like anything that is useful for processing an input text stream or text file. A lexical analyzer generally does nothing with combinations of tokens, a task left for a parser. For example, a typical lexical analyzer recognizes parentheses as tokens, but does nothing to ensure that each “(” is matched with a “)”, which happens in subsequent steps. 

# Requirement Details
Given the input C program, your lexical analyzer should do the following:

It should identify all the keywords
It should identify all the Identifiers.
It should identify the literals, such as float , characters, string literals, decimals.
It should identify the arrays.
# sample output
![la_1](https://github.com/user-attachments/assets/40b7f481-9d98-4f9d-96c9-7f6e7c2b1b4c)
# Fig1: Usage
![la_2](https://github.com/user-attachments/assets/693b1d66-7891-41a4-870d-8fd8b775f5a4)
# Fig2: Sample C File to be Parsed
![la_3](https://github.com/user-attachments/assets/c65befc9-f8c3-4209-a786-67977ba4f4d5)

