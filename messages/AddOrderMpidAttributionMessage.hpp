#ifndef KWONT_ADD_ORDER_MPID_ATTRIBUTION_MESSAGE_HPP
#define KWONT_ADD_ORDER_MPID_ATTRIBUTION_MESSAGE_HPP

#include "AddOrderNoMpidMessage.hpp"

struct AddOrderMpidAttributionMessage : AddOrderNoMpidMessage {
    std::string attribution;

    explicit AddOrderMpidAttributionMessage(std::span<char> rawData);
};

#endif
