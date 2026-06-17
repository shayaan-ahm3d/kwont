#include "OrderReplaceMessage.hpp"

OrderReplaceMessage::OrderReplaceMessage(const std::span<char> rawData) : Message(rawData) {
    originalOrderReferenceNumber = (uint64_t)rawData.at(11) << (7*BITS_PER_BYTE) |
        (uint64_t)rawData.at(12) << (6*BITS_PER_BYTE) |
        (uint64_t)rawData.at(13) << (5*BITS_PER_BYTE) |
        (uint64_t)rawData.at(14) << (4*BITS_PER_BYTE) |
        (uint64_t)rawData.at(15) << (3*BITS_PER_BYTE) |
        (uint64_t)rawData.at(16) << (2*BITS_PER_BYTE) |
        (uint64_t)rawData.at(17) << BITS_PER_BYTE |
        (uint64_t)rawData.at(18);
    newOrderReferenceNumber = (uint64_t)rawData.at(19) << (7*BITS_PER_BYTE) |
        (uint64_t)rawData.at(20) << (6*BITS_PER_BYTE) |
        (uint64_t)rawData.at(21) << (5*BITS_PER_BYTE) |
        (uint64_t)rawData.at(22) << (4*BITS_PER_BYTE) |
        (uint64_t)rawData.at(23) << (3*BITS_PER_BYTE) |
        (uint64_t)rawData.at(24) << (2*BITS_PER_BYTE) |
        (uint64_t)rawData.at(25) << BITS_PER_BYTE |
        (uint64_t)rawData.at(26);
    shares = rawData.at(27) << (3*BITS_PER_BYTE)
        | rawData.at(28) << (2*BITS_PER_BYTE)
        | rawData.at(29) << BITS_PER_BYTE
        | rawData.at(30);
    price = rawData.at(27) << (3*BITS_PER_BYTE)
        | rawData.at(28) << (2*BITS_PER_BYTE)
        | rawData.at(29) << BITS_PER_BYTE
        | rawData.at(30);
}
