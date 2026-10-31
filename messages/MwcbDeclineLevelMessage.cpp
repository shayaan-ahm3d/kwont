#include "MwcbDeclineLevelMessage.hpp"
#include "Message.hpp"

MwcbDeclineLevelMessage::MwcbDeclineLevelMessage(const std::span<const char> rawData) : Message(rawData) {
    level1 = static_cast<uint64_t>(rawData.at(11)) << (7*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(12)) << (6*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(13)) << (5*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(14)) << (4*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(15)) << (3*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(16)) << (2*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(17)) << BITS_PER_BYTE
        | static_cast<uint64_t>(rawData.at(18));
    level2 = static_cast<uint64_t>(rawData.at(19)) << (7*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(20)) << (6*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(21)) << (5*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(22)) << (4*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(23)) << (3*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(24)) << (2*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(25)) << BITS_PER_BYTE
        | static_cast<uint64_t>(rawData.at(26));
    level3 = static_cast<uint64_t>(rawData.at(27)) << (7*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(28)) << (6*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(29)) << (5*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(30)) << (4*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(31)) << (3*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(32)) << (2*BITS_PER_BYTE)
        | static_cast<uint64_t>(rawData.at(33)) << BITS_PER_BYTE
        | static_cast<uint64_t>(rawData.at(34));
}
