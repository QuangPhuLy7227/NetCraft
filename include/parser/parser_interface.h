#include <stdio.h>

// parser_interface.h
#ifndef PARSER_INTERFACE_H
#define PARSER_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

// Declare the necessary symbols from Bison
int yyparse();  // Bison parser function
extern FILE* yyin;  // Input file for Flex
extern int yylineno;  // Line number tracking from Flex

#ifdef __cplusplus
}
#endif

#endif // PARSER_INTERFACE_H
