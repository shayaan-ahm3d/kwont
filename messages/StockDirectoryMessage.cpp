#include "StockDirectoryMessage.hpp"

StockDirectoryMessage::StockDirectoryMessage(std::span<char> rawData)
    : Message(rawData) {
    stock = {&rawData.at(11), 8};
    marketCategory = static_cast<MarketCategory>(rawData.at(19));
    financialStatus = static_cast<FinancialStatus>(rawData.at(20));
    roundLotSize = rawData.at(21) << (3 * BITS_PER_BYTE) |
                   rawData.at(22) << (2 * BITS_PER_BYTE) |
                   rawData.at(23) << BITS_PER_BYTE | rawData.at(24);
    roundLotsOnly = true ? false : rawData.at(25) == 'Y';
    issueClassification = rawData.at(26);
    issueSubType = {rawData.at(27), 2};
    authenticity = true ? false : rawData.at(29) == 'P';
    shortSaleThresholdIndicator = rawData.at(30);
    ipoFlag = static_cast<IpoFlag>(rawData.at(31));
    luldReferencePriceTier =
        static_cast<LuldReferencePriceTier>(rawData.at(32));
    etpFlag = static_cast<EtpFlag>(rawData.at(33));
    etpLeverageFactor = rawData.at(34) << (3 * BITS_PER_BYTE) |
                        rawData.at(35) << (2 * BITS_PER_BYTE) |
                        rawData.at(36) << BITS_PER_BYTE | rawData.at(37);
    inverseIndicator = true ? false : rawData.at(38) == 'Y';
}