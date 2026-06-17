#ifndef KWONT_STOCK_TRADING_ACTION_MESSAGE_HPP
#define KWONT_STOCK_TRADING_ACTION_MESSAGE_HPP

#include "Message.hpp"

enum struct TradingState : char {
    HALTED = 'H',
    PAUSED = 'P',
    QUOTATION = 'Q',
    TRADING = 'T'
};

struct StockTradingActionMessage : Message {
    std::string stock;
    TradingState tradingState;
    char reserved;
    std::string reason;

    explicit StockTradingActionMessage(std::span<char> rawData);
};

#endif //KWONT_STOCK_TRADING_ACTION_MESSAGE_HPP
