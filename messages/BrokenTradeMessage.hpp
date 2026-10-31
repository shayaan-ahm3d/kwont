#ifndef KWONT_BROKEN_TRADE_MESSAGE_HPP
#define KWONT_BROKEN_TRADE_MESSAGE_HPP

#include "Message.hpp"

struct BrokenTradeMessage : Message {
    uint64_t matchNumber;

    explicit BrokenTradeMessage(std::span<const char> rawData);
};

#endif
