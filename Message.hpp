#ifndef KWONT_MESSAGE_HPP
#define KWONT_MESSAGE_HPP

#include <cstdint>
#include <chrono>

// Values taken from NASDAQ TotalView-Itch 5.0 specification:
// https://www.nasdaqtrader.com/content/technicalsupport/specifications/dataproducts/NQTVITCHSpecification.pdf
enum struct MessageType : uint8_t {
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

struct Message {
    MessageType messageType;
    uint32_t stockLocate;
    uint32_t trackingNumber;
    std::chrono::nanoseconds timestamp; // since midnight that day
    explicit Message(std::vector<uint8_t> rawData);
private:
    virtual void parseTimestamp();
};

#endif //KWONT_MESSAGE_HPP
