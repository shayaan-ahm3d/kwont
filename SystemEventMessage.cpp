#include "SystemEventMessage.hpp"
#include <cassert>
#include <utility>

SystemEventMessage::SystemEventMessage(std::vector<uint8_t> rawData) : Message(rawData) {
    assert(rawData.size() == sizeof(SystemEventMessage));
    assert(rawData.at(0) == std::to_underlying(MessageType::SYSTEM_EVENT));

    messageType = MessageType::SYSTEM_EVENT;

}
