#ifndef PARSER_H
#define PARSER_H

#ifdef __cplusplus
extern "C" {
#endif

int yyparse(void);             // Change to void parameter
int yylex(void);               // Change to void parameter
void yyerror(const char*);     // Keep as is

#ifdef __cplusplus
}
#endif

// Rest of your header remains the same
#endif // PARSER_H