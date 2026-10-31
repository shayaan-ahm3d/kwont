#ifndef KWONT_REG_SHO_RESTRICTION_MESSAGE_HPP
#define KWONT_REG_SHO_RESTRICTION_MESSAGE_HPP

#include "Message.hpp"

enum struct RegShoAction : char {
    NO_PRICE_TEST = '0',
    PRICE_RESTRICTION_TEST = '1',
    PRICE_RESTRICTION_REMAINS = '2'
};

struct RegShoRestrictionMessage : Message {
    std::string stock;
    RegShoAction regShoAction;

    explicit RegShoRestrictionMessage(std::span<const char> rawData);
};

#endif
