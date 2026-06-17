#ifndef KWONT_OPERATIONAL_HALT_MESSAGE_HPP
#define KWONT_OPERATIONAL_HALT_MESSAGE_HPP

#include "Message.hpp"

enum struct MarketCode : char {
    NASDAQ = 'Q',
    BX = 'B',
    PSX = 'X'
};

struct OperationalHaltMessage : Message {
    std::string stock;
    MarketCode marketCode;
    bool operationalHaltAction;

    explicit OperationalHaltMessage(std::span<char> rawData);
};

#endif
