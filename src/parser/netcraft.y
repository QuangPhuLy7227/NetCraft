%{
#include <iostream>
#include <vector>
#include <cstring>
#include "networking/protocols.h"
#include "cli/cli.h"

// Function prototypes
std::vector<Protocol> getAvailableProtocols();
void displayProtocolsByStack(const std::vector<Protocol>& protocols);

extern "C" {
    int yylex(void);
    void yyerror(const char* s);
}
%}

%union {
    char* string;
}

%token <string> IDENTIFIER LAYER
%token LOAD_PROTOCOLS LIST_PROTOCOLS LIST_PROTOCOLS_BY_STACK STACK NUMBER
%token '{' '}' ':' ';'
%start program
%debug

%destructor {
    free($$);
} IDENTIFIER LAYER

%%

program:
    commands
    ;

commands:
    commands command ';'
    | command ';'
    ;

command:
    LOAD_PROTOCOLS
    {
        std::vector<Protocol> protocols = getAvailableProtocols();
        std::cout << "Protocols loaded successfully.\n";
    }
    |
    LIST_PROTOCOLS
    {
        std::vector<Protocol> protocols = getAvailableProtocols();
        std::cout << "Available Protocols:\n";
        for (const auto& protocol : protocols) {
            std::cout << "- " << protocol.name << ": " << protocol.details << "\n";
        }
    }
    |
    LIST_PROTOCOLS_BY_STACK
    {
        std::vector<Protocol> protocols = getAvailableProtocols();
        std::cout << "Protocols by Stack:\n";
        displayProtocolsByStack(protocols);
    }
    |
    STACK '{' layer_definitions '}'
    {
        std::cout << "Stack defined successfully.\n";
    }
    ;

layer_definitions:
    layer_definition
    | layer_definitions layer_definition
    ;

layer_definition:
    LAYER ':' IDENTIFIER ';'
    {
        printf("Layer: %s - Protocol: %s\n", $1, $3);
        free($1);
        free($3);
    }
    ;

%%
