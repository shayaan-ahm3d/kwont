#ifndef KWONT_MARKET_PARTICIPANT_POSITION_HPP
#define KWONT_MARKET_PARTICIPANT_POSITION_HPP

#include "Message.hpp"
#include <string>

enum struct MarketMakerMode : char {
    NORMAL = 'N',
    PASSIVE = 'P',
    SYNDICATE = 'S',
    PRESYNDICATE = 'R',
    PENALTY = 'L'
};

enum struct MarketParticipantState : char {
    ACTIVE = 'A',
    EXCUSED = 'E',
    WITHDRAWN = 'W',
    SUSPENDED = 'S',
    DELETED = 'D'
};

struct MarketParticipantPositionMessage : Message {
    std::string mpid;
    std::string stock;
    bool primaryMarketMaker;
    MarketMakerMode marketMakerMode;
    MarketParticipantState marketParticipantState;

    explicit MarketParticipantPositionMessage(std::span<const char> rawData);
};

#endif
