#ifndef KWONT_SYSTEM_EVENT_MESSAGE_HPP
#define KWONT_SYSTEM_EVENT_MESSAGE_HPP

#include "Message.hpp"

enum struct SystemEventCode : char {
    START_OF_MESSAGES = 'O',
    START_OF_SYSTEM_HOURS = 'S',
    START_OF_MARKET_HOURS = 'Q',
    END_OF_MARKET_HOURS = 'M',
    END_OF_SYSTEM_HOURS = 'E',
    END_OF_MESSAGES = 'C'
};

struct SystemEventMessage : Message {
    SystemEventCode eventCode;

    explicit SystemEventMessage(std::span<char> rawData);
};

#endif  // KWONT_SYSTEM_EVENT_MESSAGE_HPP
