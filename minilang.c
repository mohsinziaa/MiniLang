#include <stdio.h>
#include <string.h>
#include "minilang.h"

// External declarations
extern int yylex();
extern FILE *yyin;
extern int yylineno;
extern char *yytext;

int main(int argc, char *argv[])
{
    // Check if the input file is provided
    if (argc < 2)
    {
        fprintf(stderr, "Error: Input file not provided.\n");
        return 1;
    }

    // Open the input file
    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile)
    {
        fprintf(stderr, "Error: Unable to open input file.\n");
        return 1;
    }

    // Set yyin to the input file
    yyin = inputFile;

    // Get the first token
    int token = yylex();

    // Loop through tokens until the end of file
    while (token)
    {
        // Switch statement to handle different token types
        switch (token)
        {
        case DATATYPE:
            printf("Text: %s, Token: %d, DATATYPE\n", yytext, token);
            break;

        case KEYWORD:
            printf("Text: %s, Token: %d, KEYWORD\n", yytext, token);
            break;

        case OPERATOR:
            printf("Text: %s, Token: %d, OPERATOR\n", yytext, token);
            break;

        case IDENTIFIER:
            printf("Text: %s, Token: %d, IDENTIFIER\n", yytext, token);
            break;

        case INT_LITERAL:
            printf("Text: %s, Token: %d, INT LITERAL\n", yytext, token);
            break;

        case PARENTHESIS:
            printf("Text: %s, Token: %d, PARENTHESIS\n", yytext, token);
            break;

        case COMMENT:
            printf("Text: %s, Token: %d, COMMENT\n", yytext, token);
            break;

        case STRING_LITERAL:
            printf("Text: %s, Token: %d, STRING\n", yytext, token);
            break;

        default:
            break;
        }

        // Get the next token
        token = yylex();
    }

    // Close the input file
    fclose(inputFile);

    return 0;
}
