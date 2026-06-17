#include "CrossTradeMessage.hpp"

CrossTradeMessage::CrossTradeMessage(const std::span<char> rawData) : Message(rawData) {
    shares = rawData.at(11) << (3*BITS_PER_BYTE) |
        rawData.at(12) << (2*BITS_PER_BYTE) |
        rawData.at(13) << BITS_PER_BYTE |
        rawData.at(14);
    stock = {&rawData.at(19), 8};
    crossPrice = rawData.at(27) << (3*BITS_PER_BYTE) |
        rawData.at(28) << (2*BITS_PER_BYTE) |
        rawData.at(29) << BITS_PER_BYTE |
        rawData.at(30);
    matchNumber = (uint64_t)rawData.at(31) << (7*BITS_PER_BYTE) |
        (uint64_t)rawData.at(32) << (6*BITS_PER_BYTE) |
        (uint64_t)rawData.at(33) << (5*BITS_PER_BYTE) |
        (uint64_t)rawData.at(34) << (4*BITS_PER_BYTE) |
        (uint64_t)rawData.at(35) << (3*BITS_PER_BYTE) |
        (uint64_t)rawData.at(36) << (2*BITS_PER_BYTE) |
        (uint64_t)rawData.at(37) << BITS_PER_BYTE |
        (uint64_t)rawData.at(38);
    crossType = static_cast<CrossType>(rawData.at(39));
}
