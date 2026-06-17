#ifndef KWONT_RPII_MESSAGE_HPP
#define KWONT_RPII_MESSAGE_HPP

#include "Message.hpp"

enum struct InterestFlag : char {
    AVAILABLE_BUY_SIDE = 'B',
    AVAILABLE_SELL_SIDE = 'S',
    AVAILABLE_BOTH_SIDES = 'A',
    NOT_AVAILABLE = 'N'
};

struct RpiiMessage : Message {
    std::string stock;
    InterestFlag interestFlag;

    explicit RpiiMessage(std::span<char> rawData);
};

#endif
