#ifndef KWONT_ORDER_CANCEL_MESSAGE_HPP
#define KWONT_ORDER_CANCEL_MESSAGE_HPP

#include "Message.hpp"

struct OrderCancelMessage: Message {
    uint64_t orderReferenceNumber;
    uint32_t cancelledShares;

    explicit OrderCancelMessage(std::span<char> rawData);
};

#endif
