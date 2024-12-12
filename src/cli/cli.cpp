#include "networking/protocols.h"
#include <map>
#include <vector>
#include <iostream>

void displayProtocolsByStack(const std::vector<Protocol>& protocols) {
    // Example categorization by stack layers
    std::map<std::string, std::vector<Protocol>> stackMap = {
        {"Layer 1 (Physical)", {}},
        {"Layer 2 (Data Link)", {}},
        {"Layer 3 (Network)", {}},
        {"Layer 4 (Transport)", {}}
    };

    // Manually map protocols to layers
    for (const auto& protocol : protocols) {
        if (protocol.name == "Ethernet") {
            stackMap["Layer 2 (Data Link)"].push_back(protocol);
        } else if (protocol.name == "IPv4" || protocol.name == "IPv6") {
            stackMap["Layer 3 (Network)"].push_back(protocol);
        } else if (protocol.name == "TCP" || protocol.name == "UDP") {
            stackMap["Layer 4 (Transport)"].push_back(protocol);
        }
    }

    // Print protocols by stack
    for (const auto& [layer, protos] : stackMap) {
        std::cout << layer << ":\n";
        for (const auto& proto : protos) {
            std::cout << "  - " << proto.name << ": " << proto.details << "\n";
        }
    }
}
