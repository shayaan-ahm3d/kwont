#include "Message.hpp"
#include <cassert>
#include <chrono>
#include <cstdint>

[[nodiscard]] static std::chrono::nanoseconds parseTimestamp(
    const std::span<char> rawData) {
    uint64_t tempTimestamp = 0;  // only get 6 bytes of data so most significant
                                 // 2 bytes should be 0s
    tempTimestamp |= ((uint64_t)rawData.at(5) << (5 * BITS_PER_BYTE)) |
                     ((uint64_t)rawData.at(6) << (4 * BITS_PER_BYTE)) |
                     ((uint64_t)rawData.at(7) << (3 * BITS_PER_BYTE)) |
                     ((uint64_t)rawData.at(8) << (2 * BITS_PER_BYTE)) |
                     ((uint64_t)rawData.at(9) << (1 * BITS_PER_BYTE)) |
                     (uint64_t)rawData.at(10);
    // assuming conversion should work as 6 bytes of the unsigned 64b num
    // should fit within 8B of signed 64b num
    return std::chrono::nanoseconds{tempTimestamp};  // TODO: check for RVO
}

Message::Message(const std::span<char> rawData) {
    messageType = static_cast<MessageType>(
        rawData.at(0));  // raw data is same as underlying value of the enum
    assert(rawData.at(1) == (uint8_t)0x0);
    assert(rawData.at(2) ==
           (uint8_t)0x0);  // stockLocate always 0 for system event message
    stockLocate = 0;
    trackingNumber = (rawData.at(3) << BITS_PER_BYTE) + rawData.at(4);
    timestamp = parseTimestamp(rawData);
}
