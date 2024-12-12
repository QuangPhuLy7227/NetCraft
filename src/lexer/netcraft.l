%{
#include "parser/parser.h"
#include <cstring> 
#include "netcraft.tab.h"
extern YYSTYPE yylval;
extern "C" int yyparse();
extern "C" void yyerror(const char*);
%}

%option noyywrap
%option yylineno

ID      [a-zA-Z_][a-zA-Z0-9_]*  
SYM     [{}:;,.()]             

%%
[ \t\r\n]+                ; 
"load_protocols"          return LOAD_PROTOCOLS;
"list_protocols"          return LIST_PROTOCOLS;
"list_protocols_by_stack" return LIST_PROTOCOLS_BY_STACK;
"stack"                   return STACK;
"layer"[0-9]+             { yylval.string = strdup(yytext); return LAYER; }
"{"                       return '{';
"}"                       return '}';
":"                       return ':';
";"                       return ';';
{ID}                      { yylval.string = strdup(yytext); return IDENTIFIER; }
[0-9]+                    return NUMBER;
.                         { printf("Unknown character: %s\n", yytext); }
%%
