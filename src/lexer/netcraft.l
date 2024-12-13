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
STRING  \"([^\\\"]|\\.)*\"               

%%
[ \t\r\n]+                ; 
"load_protocols"          return LOAD_PROTOCOLS;
"list_protocols"          return LIST_PROTOCOLS;
"list_protocols_by_stack" return LIST_PROTOCOLS_BY_STACK;
"stack"                   return STACK;
"craft_packet"            return CRAFT_PACKET;
"view_packet"             return VIEW_PACKET;
"modify_packet"           return MODIFY_PACKET;
"send_packet"             return SEND_PACKET;
"protocol"                return PROTOCOL;
"src_port"                return SRC_PORT;
"dst_port"                return DST_PORT;
"payload"                 return PAYLOAD;
"layer"[0-9]+             { yylval.string = strdup(yytext); return LAYER; }
"{"                       return '{';
"}"                       return '}';
":"                       return ':';
";"                       return ';';
{ID}                      { yylval.string = strdup(yytext); return IDENTIFIER; }
{STRING}                  { yylval.string = strdup(yytext + 1); yylval.string[strlen(yylval.string) - 1] = '\0'; return STRING_LITERAL; }
[0-9]+                    { yylval.number = atoi(yytext); return NUMBER; }
{SYM}                     return yytext[0];
.                         { printf("Unknown character: %s\n", yytext); }
%%
