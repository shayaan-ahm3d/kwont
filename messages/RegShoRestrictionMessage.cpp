#include "RegShoRestrictionMessage.hpp"

RegShoRestrictionMessage::RegShoRestrictionMessage(std::span<const char> rawData) : Message(rawData) {
    stock = {&rawData.at(11), 8};
    regShoAction = static_cast<RegShoAction>(rawData.at(19));
}
