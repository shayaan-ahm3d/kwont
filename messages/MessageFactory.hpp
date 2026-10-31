#ifndef KWONT_MESSAGE_FACTORY_HPP
#define KWONT_MESSAGE_FACTORY_HPP

#include <memory>

#include "Message.hpp"

class MessageFactory {
public:
    static std::unique_ptr<Message> create(const char* messageType);
};

#endif  // KWONT_MESSAGE_FACTORY_HPP
