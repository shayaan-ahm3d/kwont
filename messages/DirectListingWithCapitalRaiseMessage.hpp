#ifndef KWONT_DIRECT_LISTING_WITH_CAPITAL_RAISE_MESSAGE_HPP
#define KWONT_DIRECT_LISTING_WITH_CAPITAL_RAISE_MESSAGE_HPP

#include <cstdint>
#include "Message.hpp"

struct DirectListingWithCapitalRaiseMessage : Message {
    std::string stock;
    bool openEligibilityStatus;
    uint32_t minAllowablePrice; // price(4)
    uint32_t maxAllowablePrice; // price(4)
    uint32_t nearExecutionPrice; // price(4)
    uint64_t nearExecutionTime; // what unit lol
    uint32_t lowerPriceRangeCollar;
    uint32_t upperPriceRangeCollar;

    explicit DirectListingWithCapitalRaiseMessage(std::span<char> rawData);
};

#endif
