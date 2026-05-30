#include "Message.hpp"
#include <vector>

Message::Message(std::vector<uint8_t> rawData) {
    messageType = static_cast<MessageType>(rawData.at(0));
    stockLocate = static_cast<MessageType>(rawData);
};
