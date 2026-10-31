#ifndef KWONT_ADD_ORDER_NO_MPID_MESSAGE_HPP
#define KWONT_ADD_ORDER_NO_MPID_MESSAGE_HPP

#include <cstdint>
#include "Message.hpp"

struct AddOrderNoMpidMessage : Message {
    uint64_t orderReferenceNumber;
    bool isBuy;
    uint32_t shares;
    std::string stock;
    uint32_t price; // price(4)

    explicit AddOrderNoMpidMessage(std::span<const char> rawData);
};

#endif
