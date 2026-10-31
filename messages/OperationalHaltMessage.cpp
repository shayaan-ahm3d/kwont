#include "OperationalHaltMessage.hpp"

OperationalHaltMessage::OperationalHaltMessage(const std::span<const char> rawData) : Message(rawData) {
    stock = {&rawData.at(11), 8};
    marketCode = static_cast<MarketCode>(rawData.at(19));
    operationalHaltAction = true ? false : rawData.at(20) == 'H';
}
