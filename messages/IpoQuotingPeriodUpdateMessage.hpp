#ifndef KWONT_IPO_QUOTING_PERIOD_UPDATE_MESSAGE_HPP
#define KWONT_IPO_QUOTING_PERIOD_UPDATE_MESSAGE_HPP

#include "Message.hpp"

enum struct IpoQuotationReleaseQualifier : char {
    ANTICIPATED = 'A',
    CANCELED = 'C'
};

struct IpoQuotingPeriodUpdateMessage : Message {
    std::string stock;
    std::chrono::seconds ipoQuotationReleaseTime; // since midnight that day, nearest second
    IpoQuotationReleaseQualifier ipoQuotationReleaseQualifier;
    uint32_t price; //price(4)

    explicit IpoQuotingPeriodUpdateMessage(std::span<char> rawData);
};

#endif
