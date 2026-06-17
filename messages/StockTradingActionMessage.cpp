#include "StockTradingActionMessage.hpp"

StockTradingActionMessage::StockTradingActionMessage(std::span<char> rawData) : Message(rawData) {
    stock = {&rawData.at(11), 8};
    tradingState = static_cast<TradingState>(rawData.at(19));
    reserved = rawData.at(20);
    reason = {&rawData.at(21), 4};
}
