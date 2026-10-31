#include "SystemEventMessage.hpp"
#include <cassert>
#include <utility>

SystemEventMessage::SystemEventMessage(const std::span<const char> rawData) : Message(rawData) {
    assert(rawData.size() == 12);
    assert(rawData.at(0) == std::to_underlying(MessageType::SYSTEM_EVENT));
    assert(stockLocate == 0); // stockLocate always 0 for system event message
    eventCode = static_cast<SystemEventCode>(rawData.at(11));  // same underlying type
}
