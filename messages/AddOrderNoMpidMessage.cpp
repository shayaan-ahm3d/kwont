#include "AddOrderNoMpidMessage.hpp"
#include <cstdint>
#include "Message.hpp"

AddOrderNoMpidMessage::AddOrderNoMpidMessage(const std::span<const char> rawData) : Message(rawData) {
    orderReferenceNumber = static_cast<uint64_t>(rawData.at(11)) << (7*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(12)) << (6*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(13)) << (5*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(14)) << (4*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(15)) << (3*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(16)) << (2*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(17)) << BITS_PER_BYTE |
        static_cast<uint64_t>(rawData.at(18));
    isBuy = true ? false : rawData.at(19) == 'B';
    shares = rawData.at(20) << (3*BITS_PER_BYTE)
        | rawData.at(21) << (2*BITS_PER_BYTE)
        | rawData.at(22) << BITS_PER_BYTE
        | rawData.at(23);
    stock = {&rawData.at(24), 8};
    price = rawData.at(32) << (3*BITS_PER_BYTE)
        | rawData.at(33) << (2*BITS_PER_BYTE)
        | rawData.at(34) << BITS_PER_BYTE
        | rawData.at(35);
}
