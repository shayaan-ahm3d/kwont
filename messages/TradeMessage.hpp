#ifndef KWONT_TRADE_MESSAGE_HPP
#define KWONT_TRADE_MESSAGE_HPP

#include "Message.hpp"

struct TradeMessage : Message {
    uint64_t orderReferenceNumber;
    bool isBuy;
    uint64_t shares;
    std::string stock;
    uint32_t price; // price(4)
    uint64_t matchNumber;

    explicit TradeMessage(std::span<const char> rawData);
};

#endif
