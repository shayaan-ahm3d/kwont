#ifndef KWONT_ORDER_EXECUTED_WITH_PRICE_MESSAGE_HPP
#define KWONT_ORDER_EXECUTED_WITH_PRICE_MESSAGE_HPP

#include "OrderExecutedMessage.hpp"

struct OrderExecutedWithPriceMessage : OrderExecutedMessage {
    bool printable;
    uint32_t executionPrice;

    explicit OrderExecutedWithPriceMessage(std::span<const char> rawData);
};

#endif
