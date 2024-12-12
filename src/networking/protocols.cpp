#include "networking/protocols.h"
#include <boost/asio.hpp>
#include <iostream>

std::vector<Protocol> getAvailableProtocols() {
    std::vector<Protocol> protocols;

    try {
        // Use Boost.Asio to enumerate network interfaces
        boost::asio::io_context io_context;
        boost::asio::ip::tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(boost::asio::ip::host_name(), "");

        // Loop through the network interfaces
        for (const auto& endpoint : endpoints) {
            std::string interface_name = endpoint.endpoint().address().to_string();

            // Add supported protocols for each interface
            protocols.push_back({"Ethernet", "Standard Ethernet on " + interface_name});
            protocols.push_back({"IPv4", "IPv4 supported on " + interface_name});
            protocols.push_back({"IPv6", "IPv6 supported on " + interface_name});
        }

        // Add additional common protocols
        protocols.push_back({"TCP", "Transmission Control Protocol (TCP)"});
        protocols.push_back({"UDP", "User Datagram Protocol (UDP)"});

    } catch (const std::exception& e) {
        std::cerr << "Error detecting protocols: " << e.what() << std::endl;
    }

    return protocols;
}