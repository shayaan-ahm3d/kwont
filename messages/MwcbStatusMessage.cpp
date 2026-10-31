#include "MwcbStatusMessage.hpp"

MwcbStatusMessage::MwcbStatusMessage(const std::span<const char> rawData) : Message(rawData) {
    breachedLevel = static_cast<BreachedLevel>(rawData.at(11));
}
