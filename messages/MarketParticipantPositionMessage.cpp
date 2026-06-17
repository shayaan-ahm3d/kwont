#include "MarketParticipantPositionMessage.hpp"
#include <span>

MarketParticipantPositionMessage::MarketParticipantPositionMessage(std::span<char> rawData) : Message(rawData) {
    mpid = {&rawData.at(11), 4};
    stock = {&rawData.at(15), 8};
    primaryMarketMaker = true ? false : rawData.at(23) == 'Y';
    marketMakerMode = static_cast<MarketMakerMode>(rawData.at(24));
    marketParticipantState = static_cast<MarketParticipantState>(rawData.at(25));
}
