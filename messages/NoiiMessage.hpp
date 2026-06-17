#ifndef KWONT_NOII_MESSAGE_HPP
#define KWONT_NOII_MESSAGE_HPP

#include <cstdint>
#include "CrossTradeMessage.hpp"
#include "Message.hpp"

enum struct ImbalanceDirection : char {
    BUY = 'B',
    SELL = 'S',
    NONE = 'N',
    INSUFFICIENT_ORDERS = 'O',
    PAUSED = 'P'
};

enum struct PriceVariationIndicator : char {
      LESS_THAN_ONE = 'L',
      ONE = '1',
      TWO = '2',
      THREE = '3',
      FOUR = '4',
      FIVE ='5',
      SIX ='6',
      SEVEN ='7',
      EIGHT ='8',
      NINE ='9',
      TEN ='A',
      TWENTY ='B',
      THIRTY_PLUS ='C',
      CANNOT_BE_CALCULATED = ' '
};

struct NoiiMessage : Message {
    uint64_t pairedShares;
    uint64_t imbalanceShares;
    ImbalanceDirection imbalanceDirection;
    std::string stock;
    uint32_t farPrice; // price(4)
    uint32_t nearPrice; // price(4)
    uint32_t currentReferencePrice; // price(4)
    CrossType crossType;
    PriceVariationIndicator priceVariationIndicator;

    explicit NoiiMessage(std::span<char> rawData);
};

#endif
