#ifndef PROTOCOLS_H
#define PROTOCOLS_H

#include <string>
#include <vector>

// Struct to represent available protocols
struct Protocol {
    std::string name;
    std::string details;
};

std::vector<Protocol> getAvailableProtocols();

#endif