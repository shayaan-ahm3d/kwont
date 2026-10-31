#include "LuldAuctionCollarMessage.hpp"

LuldAuctionCollarMessage::LuldAuctionCollarMessage(const std::span<const char> rawData) : Message(rawData) {
    stock = {&rawData.at(11), 8};
    auctionCollarReferencePrice = rawData.at(19) << (3*BITS_PER_BYTE)
        | rawData.at(20) << (2*BITS_PER_BYTE)
        | rawData.at(21) << BITS_PER_BYTE
        | rawData.at(22);
    upperAuctionCollarPrice = rawData.at(23) << (3*BITS_PER_BYTE)
        | rawData.at(24) << (2*BITS_PER_BYTE)
        | rawData.at(25) << BITS_PER_BYTE
        | rawData.at(26);
    lowerAuctionCollarPrice = rawData.at(27) << (3*BITS_PER_BYTE)
        | rawData.at(28) << (2*BITS_PER_BYTE)
        | rawData.at(29) << BITS_PER_BYTE
        | rawData.at(30);
    auctionCollarExtension = rawData.at(31) << (3*BITS_PER_BYTE)
        | rawData.at(32) << (2*BITS_PER_BYTE)
        | rawData.at(33) << BITS_PER_BYTE
        | rawData.at(34);
}
