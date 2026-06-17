#ifndef KWONT_MWCB_STATUS_MESSAGE_HPP
#define KWONT_MWCB_STATUS_MESSAGE_HPP

#include "Message.hpp"

enum struct BreachedLevel : char {
    LEVEL1 = '1',
    LEVEL2 = '2',
    LEVEL3 = '3'
};

struct MwcbStatusMessage : Message {
    BreachedLevel breachedLevel;

    explicit MwcbStatusMessage(std::span<char> rawData);
};

#endif
