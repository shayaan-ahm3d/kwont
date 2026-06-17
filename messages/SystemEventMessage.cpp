#include "SystemEventMessage.hpp"
#include <cassert>
#include <utility>

SystemEventMessage::SystemEventMessage(std::span<char> rawData)
    : Message(rawData) {
    assert(rawData.size() == 12);
    assert(rawData.at(0) == std::to_underlying(MessageType::SYSTEM_EVENT));

    eventCode =
        static_cast<SystemEventCode>(rawData.at(11));  // same underlying type
}
