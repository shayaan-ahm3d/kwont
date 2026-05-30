#ifndef KWONT_SYSTEM_EVENT_MESSAGE_HPP
#define KWONT_SYSTEM_EVENT_MESSAGE_HPP

#include "Message.hpp"

enum struct SystemEventCode : char8_t {
    START_OF_MESSAGES = 'O',
    START_OF_SYSTEM_HOURS = 'S',
    START_OF_MARKET_HOURS = 'Q',
    END_OF_MARKET_HOURS = 'M',
    END_OF_SYSTEM_HOURS = 'E',
    END_OF_MESSAGES = 'C'
};

struct SystemEventMessage : public Message {
    SystemEventCode eventCode;

    explicit SystemEventMessage(std::vector<uint8_t>);
};

#endif //KWONT_SYSTEM_EVENT_MESSAGE_HPP
