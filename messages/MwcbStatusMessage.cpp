#include "MwcbStatusMessage.hpp"

MwcbStatusMessage::MwcbStatusMessage(std::span<char> rawData) : Message(rawData) {
    breachedLevel = static_cast<BreachedLevel>(rawData.at(11));
}
