#ifndef PACKET_CRAFTER_H
#define PACKET_CRAFTER_H

#include <string>

struct PacketDetails {
    std::string protocol;
    int src_port;
    int dst_port;
    std::string payload;
};

void craftPacket(const std::string& protocol, int src_port, int dst_port, const std::string& payload);

#endif // PACKET_CRAFTER_H
