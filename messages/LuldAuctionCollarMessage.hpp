#ifndef KWONT_LULD_AUCTION_COLLAR_MESSAGE_HPP
#define KWONT_LULD_AUCTION_COLLAR_MESSAGE_HPP

#include "Message.hpp"

struct LuldAuctionCollarMessage : Message {
    std::string stock;
    uint32_t auctionCollarReferencePrice;
    uint32_t upperAuctionCollarPrice;
    uint32_t lowerAuctionCollarPrice;
    uint32_t auctionCollarExtension;

    explicit LuldAuctionCollarMessage(std::span<const char> rawData);
};

#endif
