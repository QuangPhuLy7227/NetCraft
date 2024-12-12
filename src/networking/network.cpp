#include "networking/network.h"
#include <iostream>

void NetworkManager::listAvailableProtocols() {
    std::vector<Protocol> protocols = getAvailableProtocols();

    // Print available protocols
    std::cout << "Available Protocols:\n";
    for (const auto& protocol : protocols) {
        std::cout << "- " << protocol.name << ": " << protocol.details << "\n";
    }
}
