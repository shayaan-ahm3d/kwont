#include "OrderDeleteMessage.hpp"

OrderDeleteMessage::OrderDeleteMessage(const std::span<char> rawData) : Message(rawData) {
    orderReferenceNumber = (uint64_t)rawData.at(11) << (7*BITS_PER_BYTE) |
        (uint64_t)rawData.at(12) << (6*BITS_PER_BYTE) |
        (uint64_t)rawData.at(13) << (5*BITS_PER_BYTE) |
        (uint64_t)rawData.at(14) << (4*BITS_PER_BYTE) |
        (uint64_t)rawData.at(15) << (3*BITS_PER_BYTE) |
        (uint64_t)rawData.at(16) << (2*BITS_PER_BYTE) |
        (uint64_t)rawData.at(17) << BITS_PER_BYTE |
        (uint64_t)rawData.at(18);
}
