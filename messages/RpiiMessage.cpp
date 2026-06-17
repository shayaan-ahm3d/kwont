#include "RpiiMessage.hpp"

RpiiMessage::RpiiMessage(const std::span<char> rawData) : Message(rawData) {
    stock = {&rawData.at(11), 8};
    interestFlag = static_cast<InterestFlag>(rawData.at(19));
}
