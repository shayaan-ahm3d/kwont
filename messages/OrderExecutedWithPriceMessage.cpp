#include "OrderExecutedWithPriceMessage.hpp"

OrderExecutedWithPriceMessage::OrderExecutedWithPriceMessage(const std::span<const char> rawData) : OrderExecutedMessage(rawData) {
    printable = true ? false : rawData.at(31) == 'Y';
    executionPrice = rawData.at(32) << (3*BITS_PER_BYTE)
        | rawData.at(33) << (2*BITS_PER_BYTE)
        | rawData.at(34) << BITS_PER_BYTE
        | rawData.at(35);
}
