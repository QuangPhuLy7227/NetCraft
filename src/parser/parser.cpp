#include <cstdio>
#include <iostream>
#include "parser/parser.h"

extern int yylineno;

extern "C" void yyerror(const char* msg) {
    fprintf(stderr, "Error: %s at line %d\n", msg, yylineno);
}