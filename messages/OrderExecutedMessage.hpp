#ifndef KWONT_ORDER_EXECUTED_MESSAGE_HPP
#define KWONT_ORDER_EXECUTED_MESSAGE_HPP

#include <cstdint>
#include "Message.hpp"

struct OrderExecutedMessage : Message {
    uint64_t orderReferenceNumber;
    uint32_t executedShares;
    uint64_t matchNumber;

    explicit OrderExecutedMessage(std::span<const char> rawData);
};

#endif
