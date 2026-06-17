#ifndef KWONT_CROSS_TRADE_MESSAGE_HPP
#define KWONT_CROSS_TRADE_MESSAGE_HPP

#include <cstdint>
#include "Message.hpp"

enum struct CrossType : char {
    NASDAQ_OPENING_CROSS = 'O',
    NASDAQ_CLOSING_CROSS = 'C',
    CROSS_FOR_IPO_AND_HALTED_SECURITIES = 'H',
    EXTENDED_TRADING_CLOSE = 'A'
};

struct CrossTradeMessage : Message {
    uint64_t shares;
    std::string stock;
    uint32_t crossPrice;
    uint64_t matchNumber;
    CrossType crossType;

    explicit CrossTradeMessage(std::span<char> rawData);
};

#endif
