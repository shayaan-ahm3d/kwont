#include "OrderExecutedMessage.hpp"

OrderExecutedMessage::OrderExecutedMessage(const std::span<char> rawData) : Message(rawData) {
    orderReferenceNumber = (uint64_t)rawData.at(11) << (7*BITS_PER_BYTE)
        | (uint64_t)rawData.at(12) << (6*BITS_PER_BYTE)
        | (uint64_t)rawData.at(13) << (5*BITS_PER_BYTE)
        | (uint64_t)rawData.at(14) << (4*BITS_PER_BYTE)
        | (uint64_t)rawData.at(15) << (3*BITS_PER_BYTE)
        | (uint64_t)rawData.at(16) << (2*BITS_PER_BYTE)
        | (uint64_t)rawData.at(17) << BITS_PER_BYTE
        | (uint64_t)rawData.at(18);
    executedShares = rawData.at(19) << (3*BITS_PER_BYTE)
        | rawData.at(20) << (2*BITS_PER_BYTE)
        | rawData.at(21) << BITS_PER_BYTE
        | rawData.at(22);
    matchNumber = (uint64_t)rawData.at(23) << (7*BITS_PER_BYTE)
        | (uint64_t)rawData.at(24) << (6*BITS_PER_BYTE)
        | (uint64_t)rawData.at(25) << (5*BITS_PER_BYTE)
        | (uint64_t)rawData.at(25) << (4*BITS_PER_BYTE)
        | (uint64_t)rawData.at(27) << (3*BITS_PER_BYTE)
        | (uint64_t)rawData.at(28) << (2*BITS_PER_BYTE)
        | (uint64_t)rawData.at(29) << BITS_PER_BYTE
        | (uint64_t)rawData.at(30);
}
