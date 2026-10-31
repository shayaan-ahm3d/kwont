#ifndef KWONT_STOCK_DIRECTORY_MESSAGE_HPP
#define KWONT_STOCK_DIRECTORY_MESSAGE_HPP

#include "Message.hpp"

enum struct MarketCategory : char {
    // NASDAQ-listed instruments
    NASDAQ_GLOBAL_SELECT_MARKET = 'Q',
    NASDAQ_GLOBAL_MARKET = 'G',
    NASDAQ_CAPITAL_MARKET = 'S',
    // Non-NASDAQ-listed instruments
    NYSE = 'N',
    NYSE_AMERICAN = 'A',
    NYSE_ARCA = 'P',
    BATS_Z = 'Z',
    INVESTORS = 'V',
    NOT_AVAILABLE = ' '
};

enum struct FinancialStatus : char {
    // NASDAQ-listed instruments
    DEFICIENT = 'D',
    DELINQUENT = 'E',
    BANKRUPT = 'Q',
    SUSPENDED = 'S',
    DEFICIENT_AND_BANKRUPT = 'G',
    DEFICIENT_AND_DELINQUENT = 'H',
    DELINQUENT_AND_BANKRUPT = 'J',
    DEFICIENT_DELINQUENT_AND_BANKRUPT = 'K',
    CREATIONS_REDEMPTIONS_SUSPENDED = 'C',
    NORMAL = 'N',
    // Non-NASDAQ-listed instruments
    NOT_AVAILABLE = ' '
};

enum struct IpoFlag : char { IPO = 'Y', NON_IPO = 'N', NOT_AVAILABLE = ' ' };

enum struct LuldReferencePriceTier : char {
    TIER_1 = '1',
    TIER_2 = '2',
    NOT_AVAILABLE = ' '
};

enum struct EtpFlag : char { ETP = 'Y', NOT_ETP = 'N', NOT_AVAILABLE = ' ' };

struct StockDirectoryMessage : Message {
    std::string stock;
    MarketCategory marketCategory;
    FinancialStatus financialStatus;
    uint32_t roundLotSize;
    bool roundLotsOnly;
    char issueClassification;
    std::string issueSubType;
    bool authenticity;
    bool shortSaleThresholdIndicator;
    IpoFlag ipoFlag;
    LuldReferencePriceTier luldReferencePriceTier;
    EtpFlag etpFlag;
    uint32_t etpLeverageFactor;
    bool inverseIndicator;

    explicit StockDirectoryMessage(std::span<const char> rawData);
};

#endif  // KWONT_STOCK_DIRECTORY_MESSAGE_HPP
