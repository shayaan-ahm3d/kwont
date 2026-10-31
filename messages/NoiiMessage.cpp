#include "NoiiMessage.hpp"
#include "CrossTradeMessage.hpp"

NoiiMessage::NoiiMessage(const std::span<const char> rawData) : Message(rawData) {
    pairedShares = static_cast<uint64_t>(rawData.at(11)) << (7*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(12)) << (6*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(13)) << (5*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(14)) << (4*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(15)) << (3*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(16)) << (2*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(17)) << BITS_PER_BYTE |
        static_cast<uint64_t>(rawData.at(18));
    imbalanceShares = static_cast<uint64_t>(rawData.at(19)) << (7*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(20)) << (6*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(21)) << (5*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(22)) << (4*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(23)) << (3*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(24)) << (2*BITS_PER_BYTE) |
        static_cast<uint64_t>(rawData.at(25)) << BITS_PER_BYTE |
        static_cast<uint64_t>(rawData.at(26));
    imbalanceDirection = static_cast<ImbalanceDirection>(rawData.at(27));
    stock = {&rawData.at(28), 8};
    farPrice = rawData.at(36) << (3*BITS_PER_BYTE) |
        rawData.at(37) << (2*BITS_PER_BYTE) |
        rawData.at(38) << BITS_PER_BYTE |
        rawData.at(39);
    nearPrice = rawData.at(40) << (3*BITS_PER_BYTE) |
        rawData.at(41) << (2*BITS_PER_BYTE) |
        rawData.at(42) << BITS_PER_BYTE |
        rawData.at(43);
    currentReferencePrice = rawData.at(44) << (3*BITS_PER_BYTE) |
        rawData.at(45) << (2*BITS_PER_BYTE) |
        rawData.at(46) << BITS_PER_BYTE |
        rawData.at(47);
    crossType = static_cast<CrossType>(rawData.at(48));
    priceVariationIndicator = static_cast<PriceVariationIndicator>(rawData.at(49));
}
