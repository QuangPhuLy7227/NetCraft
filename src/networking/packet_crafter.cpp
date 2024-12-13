#include "networking/packet_crafter.h"
#include <boost/asio.hpp>
#include <iostream>
#include <stdexcept>

void craftPacket(const std::string& protocol, int src_port, int dst_port, const std::string& payload) {
    try {
        // Validate protocol
        if (protocol.empty() || (protocol != "TCP" && protocol != "UDP")) {
            throw std::invalid_argument("Unsupported protocol: " + protocol);
        }

        // Validate ports
        if (src_port <= 0 || src_port > 65535 || dst_port <= 0 || dst_port > 65535) {
            throw std::invalid_argument("Invalid port values: src_port = " + std::to_string(src_port) +
                                        ", dst_port = " + std::to_string(dst_port));
        }

        // Validate payload
        if (payload.empty()) {
            throw std::invalid_argument("Payload cannot be empty");
        }

        boost::asio::io_context io_context;
        boost::asio::ip::address destination_address = boost::asio::ip::make_address("127.0.0.1");

        if (protocol == "TCP") {
            // TCP socket and connection
            boost::asio::ip::tcp::socket tcp_socket(io_context);
            boost::asio::ip::tcp::endpoint tcp_endpoint(destination_address, dst_port);
            tcp_socket.connect(tcp_endpoint);
            boost::asio::write(tcp_socket, boost::asio::buffer(payload));
            std::cout << "TCP packet crafted and sent successfully!\n";
        } else if (protocol == "UDP") {
            // UDP socket and send_to
            boost::asio::ip::udp::socket udp_socket(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), src_port));
            boost::asio::ip::udp::endpoint udp_endpoint(destination_address, dst_port);
            udp_socket.send_to(boost::asio::buffer(payload), udp_endpoint);
            std::cout << "UDP packet crafted and sent successfully!\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error crafting packet: " << e.what() << "\n";
    }
}
