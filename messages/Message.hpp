#ifndef KWONT_MESSAGE_HPP
#define KWONT_MESSAGE_HPP

#include <chrono>
#include <cstdint>

#include <frozen/unordered_map.h>
#include <frozen/unordered_set.h>

inline constexpr int BITS_PER_BYTE = 8;  // use for shifting by number of bytes

// Values taken from NASDAQ TotalView-Itch 5.0 specification:
// https://www.nasdaqtrader.com/content/technicalsupport/specifications/dataproducts/NQTVITCHSpecification.pdf
enum struct MessageType : char {
    SYSTEM_EVENT = 'S',
    STOCK_DIRECTORY = 'R',
    STOCK_TRADING_ACTION = 'H',
    REG_SHO = 'Y',
    MARKET_PARTICIPANT_POSITION = 'L',
    MWCB_DECLINE_LEVEL = 'V',
    MWCB_STATUS_LEVEL = 'W',
    IPO_QUOTING_PERIOD_UPDATE = 'K',
    LULD_AUCTION_COLLAR = 'J',
    OPERATIONAL_HALT = 'h',
    ADD_ORDER_NO_MPID_ATTRIBUTION = 'A',
    ADD_ORDER_MPID_ATTRIBUTION = 'F',
    ORDER_EXECUTED = 'E',
    ORDER_EXECUTED_WITH_PRICE = 'C',
    ORDER_CANCEL = 'X',
    ORDER_DELETE = 'D',
    ORDER_REPLACE = 'U',
    TRADE = 'P',
    CROSS_TRADE = 'Q',
    BROKEN_TRADE = 'B',
    NOII = 'I',
    RPII = 'N',
    DIRECT_LISTING_WITH_CAPITAL_RAISE = 'O'
};

constexpr frozen::unordered_set<char, 23> charToMessageType = {
    'S', 'R', 'H', 'Y', 'L', 'V', 'W', 'K', 'J', 'h', 'A', 'F',
    'E', 'C', 'X', 'D', 'U', 'P', 'Q', 'B', 'I', 'N', 'O'};

constexpr frozen::unordered_map<char, int, 23> messageTypeToSize = {
    {'S', 12}, {'R', 39}, {'H', 25}, {'Y', 20}, {'L', 26}, {'V', 35},
    {'W', 12}, {'K', 28}, {'J', 35}, {'h', 21}, {'A', 36}, {'F', 40},
    {'E', 31}, {'C', 36}, {'X', 23}, {'D', 19}, {'U', 35}, {'P', 44},
    {'Q', 40}, {'B', 19}, {'I', 50}, {'N', 20}, {'O', 48}};

struct Message {
    MessageType messageType;
    uint32_t stockLocate = 0;
    uint32_t trackingNumber = 0;
    std::chrono::nanoseconds timestamp =
        std::chrono::nanoseconds{0};  // since midnight that day

    explicit Message(std::span<char> rawData);
};

#endif  // KWONT_MESSAGE_HPP
