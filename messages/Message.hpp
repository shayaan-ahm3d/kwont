#ifndef KWONT_MESSAGE_HPP
#define KWONT_MESSAGE_HPP

#include <chrono>
#include <cstdint>

#include <frozen/unordered_map.h>
#include <frozen/unordered_set.h>

inline constexpr int BYTES_FOR_SIZE = 2; // number of bytes making up size before each message
inline constexpr int BITS_PER_BYTE = 8;  // use for shifting by number of bytes

// Since reading from sample file, also have to adhere to BinaryFile spec:
// https://nasdaqtrader.com/content/technicalSupport/specifications/dataproducts/binaryfile.pdf

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

inline std::ostream& operator<<(std::ostream& out, const MessageType value) {
    static const auto stringRepresentation = [] {
        std::unordered_map<MessageType, std::string_view> result;
        // #e to get string representation from preprocessor
        #define INSERT_ELEMENT(e) result.emplace(e, #e);
        INSERT_ELEMENT(MessageType::SYSTEM_EVENT);
        INSERT_ELEMENT(MessageType::STOCK_DIRECTORY);
        INSERT_ELEMENT(MessageType::STOCK_TRADING_ACTION);
        INSERT_ELEMENT(MessageType::REG_SHO);
        INSERT_ELEMENT(MessageType::MARKET_PARTICIPANT_POSITION);
        INSERT_ELEMENT(MessageType::MWCB_DECLINE_LEVEL);
        INSERT_ELEMENT(MessageType::MWCB_STATUS_LEVEL);
        INSERT_ELEMENT(MessageType::IPO_QUOTING_PERIOD_UPDATE);
        INSERT_ELEMENT(MessageType::LULD_AUCTION_COLLAR);
        INSERT_ELEMENT(MessageType::OPERATIONAL_HALT);
        INSERT_ELEMENT(MessageType::ADD_ORDER_NO_MPID_ATTRIBUTION);
        INSERT_ELEMENT(MessageType::ADD_ORDER_MPID_ATTRIBUTION);
        INSERT_ELEMENT(MessageType::ORDER_EXECUTED);
        INSERT_ELEMENT(MessageType::ORDER_EXECUTED_WITH_PRICE);
        INSERT_ELEMENT(MessageType::ORDER_CANCEL);
        INSERT_ELEMENT(MessageType::ORDER_DELETE);
        INSERT_ELEMENT(MessageType::ORDER_REPLACE);
        INSERT_ELEMENT(MessageType::TRADE);
        INSERT_ELEMENT(MessageType::CROSS_TRADE);
        INSERT_ELEMENT(MessageType::BROKEN_TRADE);
        INSERT_ELEMENT(MessageType::NOII);
        INSERT_ELEMENT(MessageType::RPII);
        INSERT_ELEMENT(MessageType::DIRECT_LISTING_WITH_CAPITAL_RAISE);
        #undef INSERT_ELEMENT
        return result;
    };
    return out << stringRepresentation()[value];
}

// Set of all possible characters that are a message type
constexpr frozen::unordered_set<char, 23> messageTypeCharacters = {
    'S', 'R', 'H', 'Y', 'L', 'V', 'W', 'K', 'J', 'h', 'A', 'F',
    'E', 'C', 'X', 'D', 'U', 'P', 'Q', 'B', 'I', 'N', 'O'};

constexpr frozen::unordered_map<char, int, 23> messageTypeToSize = {
    {'S', 12}, {'R', 39}, {'H', 25}, {'Y', 20}, {'L', 26}, {'V', 35},
    {'W', 12}, {'K', 28}, {'J', 35}, {'h', 21}, {'A', 36}, {'F', 40},
    {'E', 31}, {'C', 36}, {'X', 23}, {'D', 19}, {'U', 35}, {'P', 44},
    {'Q', 40}, {'B', 19}, {'I', 50}, {'N', 20}, {'O', 48}};

struct Message {
    MessageType messageType;
    uint16_t stockLocate = 0;
    uint16_t trackingNumber = 0;
    std::chrono::nanoseconds timestamp = std::chrono::nanoseconds{0};  // since midnight that day

    explicit Message(std::span<char> rawData);
    virtual ~Message() = default;
};

#endif  // KWONT_MESSAGE_HPP
