#ifndef KWONT_ORDER_REPLACE_MESSAGE_HPP
#define KWONT_ORDER_REPLACE_MESSAGE_HPP

#include "Message.hpp"

struct OrderReplaceMessage : Message {
    uint64_t originalOrderReferenceNumber;
    uint64_t newOrderReferenceNumber;
    uint32_t shares;
    uint32_t price; // price(4)

    explicit OrderReplaceMessage(std::span<char> rawData);
};

#endif
