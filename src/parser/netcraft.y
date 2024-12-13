%{
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include "networking/protocols.h"
#include "cli/cli.h"
#include "networking/packet_crafter.h"

// Function prototypes
std::vector<Protocol> getAvailableProtocols();
void displayProtocolsByStack(const std::vector<Protocol>& protocols);

extern "C" {
    int yylex(void);
    void yyerror(const char* s);
}

std::map<std::string, PacketDetails> crafted_packets;
std::string current_packet;
%}

%union {
    char* string;
    int number;
}

%token <string> IDENTIFIER LAYER
%token <string> STRING
%token <string> STRING_LITERAL
%token <number> NUMBER
%token LOAD_PROTOCOLS LIST_PROTOCOLS LIST_PROTOCOLS_BY_STACK STACK
%token CRAFT_PACKET VIEW_PACKET MODIFY_PACKET SEND_PACKET
%token PROTOCOL SRC_PORT DST_PORT PAYLOAD
%token '{' '}' ':' ';'
%start program
%debug

%type <string> protocol_field payload_field
%type <number> port_field

%destructor {
    free($$);
} IDENTIFIER LAYER STRING_LITERAL

%%

program:
    commands
    ;

commands:
    commands command
    | command
    ;

command:
    LOAD_PROTOCOLS ';'
    {
        std::vector<Protocol> protocols = getAvailableProtocols();
        std::cout << "Protocols loaded successfully.\n";
    }
    |
    LIST_PROTOCOLS ';'
    {
        std::vector<Protocol> protocols = getAvailableProtocols();
        std::cout << "Available Protocols:\n";
        for (const auto& protocol : protocols) {
            std::cout << "- " << protocol.name << ": " << protocol.details << "\n";
        }
    }
    |
    LIST_PROTOCOLS_BY_STACK ';'
    {
        std::vector<Protocol> protocols = getAvailableProtocols();
        std::cout << "Protocols by Stack:\n";
        displayProtocolsByStack(protocols);
    }
    |
    STACK '{' layer_definitions '}' ';'
    {
        std::cout << "Stack defined successfully.\n";
    }
    |
    command:
    CRAFT_PACKET IDENTIFIER '{' packet_fields '}' ';'
    {
        if (crafted_packets.find($2) != crafted_packets.end()) {
            std::cerr << "Error: Packet '" << $2 << "' already exists.\n";
        } else {
            current_packet = $2;
            crafted_packets[$2] = PacketDetails{"", 0, 0, ""};
            std::cout << "Packet '" << $2 << "' crafted.\n";
        }
        free($2);
        current_packet.clear();
    }
    |
    VIEW_PACKET IDENTIFIER ';'
    {
        auto it = crafted_packets.find($2);
        if (it != crafted_packets.end()) {
            const auto& packet = it->second;
            std::cout << "Packet '" << $2 << "':\n";
            std::cout << "  Protocol: " << packet.protocol << "\n";
            std::cout << "  Source Port: " << packet.src_port << "\n";
            std::cout << "  Destination Port: " << packet.dst_port << "\n";
            std::cout << "  Payload: " << packet.payload << "\n";
        } else {
            std::cerr << "Error: Packet '" << $2 << "' not found.\n";
        }
        free($2);
    }
    |
    MODIFY_PACKET IDENTIFIER '{' packet_fields '}' ';'
    {
        auto it = crafted_packets.find($2);
        if (it != crafted_packets.end()) {
            std::cout << "Packet '" << $2 << "' modified.\n";
        } else {
            std::cerr << "Error: Packet '" << $2 << "' not found.\n";
        }
        free($2);
    }
    |
    SEND_PACKET IDENTIFIER ';'
    {
        auto it = crafted_packets.find($2);
        if (it != crafted_packets.end()) {
            craftPacket(it->second.protocol, it->second.src_port, it->second.dst_port, it->second.payload);
        } else {
            std::cerr << "Error: Packet '" << $2 << "' not found.\n";
        }
        free($2);
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

packet_fields:
    packet_fields protocol_field
    | packet_fields port_field
    | packet_fields payload_field
    | protocol_field
    | port_field
    | payload_field
    ;

protocol_field:
    PROTOCOL ':' IDENTIFIER ';'
    {
        if (!current_packet.empty()) {
            crafted_packets[current_packet].protocol = $3;
            std::cout << "Set protocol for '" << current_packet << "': " << $3 << "\n";
        }
        free($3);
    }
    ;

port_field:
    SRC_PORT ':' NUMBER ';'
    {
        if (!current_packet.empty()) {
            crafted_packets[current_packet].src_port = $3;
            std::cout << "Set source port for '" << current_packet << "': " << $3 << "\n";
        }
    }
    |
    DST_PORT ':' NUMBER ';'
    {
        if (!current_packet.empty()) {
            crafted_packets[current_packet].dst_port = $3;
            std::cout << "Set destination port for '" << current_packet << "': " << $3 << "\n";
        }
    }
    ;

payload_field:
    PAYLOAD ':' STRING_LITERAL ';'
    {
        if (!current_packet.empty()) {
            crafted_packets[current_packet].payload = $3;
            std::cout << "Set payload for '" << current_packet << "': " << $3 << "\n";
        }
        free($3);
    }
    ;

%%