#ifndef KWONT_MWCB_DECLINE_LEVEL_MESSAGE_HPP
#define KWONT_MWCB_DECLINE_LEVEL_MESSAGE_HPP

#include "Message.hpp"

struct MwcbDeclineLevelMessage : Message {
    uint64_t level1;
    uint64_t level2;
    uint64_t level3;

    explicit MwcbDeclineLevelMessage(std::span<char> rawData);
};

#endif
