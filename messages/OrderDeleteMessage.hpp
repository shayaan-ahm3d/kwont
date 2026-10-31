#ifndef KWONT_ORDER_DELETE_MESSAGE_HPP
#define KWONT_ORDER_DELETE_MESSAGE_HPP

#include "Message.hpp"

struct OrderDeleteMessage : Message {
    uint64_t orderReferenceNumber;

    explicit OrderDeleteMessage(std::span<const char> rawData);
};

#endif
