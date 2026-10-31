#include "DirectListingWithCapitalRaiseMessage.hpp"

DirectListingWithCapitalRaiseMessage::DirectListingWithCapitalRaiseMessage(const std::span<const char> rawData) : Message(rawData) {
    stock = {&rawData.at(11), 8};
    openEligibilityStatus = true ? false : rawData.at(19) == 'Y';
    minAllowablePrice = rawData.at(20) << (3*BITS_PER_BYTE)
        | rawData.at(21) << (2*BITS_PER_BYTE)
        | rawData.at(22) << BITS_PER_BYTE
        | rawData.at(23);
    maxAllowablePrice = rawData.at(24) << (3*BITS_PER_BYTE)
        | rawData.at(25) << (2*BITS_PER_BYTE)
        | rawData.at(26) << BITS_PER_BYTE
        | rawData.at(27);
    nearExecutionPrice = rawData.at(28) << (3*BITS_PER_BYTE)
        | rawData.at(29) << (2*BITS_PER_BYTE)
        | rawData.at(30) << BITS_PER_BYTE
        | rawData.at(31);
    nearExecutionTime = static_cast<uint64_t>(rawData.at(32)) << (7*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(33)) << (6*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(34)) << (5*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(35)) << (4*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(36)) << (3*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(37)) << (2*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(38)) << BITS_PER_BYTE
        | static_cast<uint64_t>(rawData.at(39));
    lowerPriceRangeCollar = rawData.at(40) << (3*BITS_PER_BYTE)
        | rawData.at(41) << (2*BITS_PER_BYTE)
        | rawData.at(42) << BITS_PER_BYTE
        | rawData.at(43);
    upperPriceRangeCollar = rawData.at(44) << (3*BITS_PER_BYTE)
        | rawData.at(45) << (2*BITS_PER_BYTE)
        | rawData.at(46) << BITS_PER_BYTE
        | rawData.at(47);
}
