#include "MessageFactory.hpp"
#include <memory>
#include "Message.hpp"
#include "MwcbDeclineLevelMessage.hpp"
#include "OrderReplaceMessage.hpp"
#include "RegShoRestrictionMessage.hpp"
#include "StockDirectoryMessage.hpp"
#include "SystemEventMessage.hpp"
#include "StockTradingActionMessage.hpp"
#include "MarketParticipantPositionMessage.hpp"
#include "MwcbStatusMessage.hpp"
#include "IpoQuotingPeriodUpdateMessage.hpp"
#include "LuldAuctionCollarMessage.hpp"
#include "OperationalHaltMessage.hpp"
#include "AddOrderNoMpidMessage.hpp"
#include "AddOrderMpidAttributionMessage.hpp"
#include "OrderExecutedMessage.hpp"
#include "OrderExecutedWithPriceMessage.hpp"
#include "OrderCancelMessage.hpp"
#include "OrderDeleteMessage.hpp"
#include "TradeMessage.hpp"
#include "CrossTradeMessage.hpp"
#include "BrokenTradeMessage.hpp"
#include "NoiiMessage.hpp"
#include "RpiiMessage.hpp"
#include "DirectListingWithCapitalRaiseMessage.hpp"

std::unique_ptr<Message> MessageFactory::create(char* messageType) {
    std::span rawData{messageType, static_cast<size_t>(messageTypeToSize.at(*messageType))};
    switch (*messageType) {
        case 'S': return std::make_unique<SystemEventMessage>(rawData);
        case 'R': return std::make_unique<StockDirectoryMessage>(rawData);
        case 'H': return std::make_unique<StockTradingActionMessage>(rawData);
        case 'Y': return std::make_unique<RegShoRestrictionMessage>(rawData);
        case 'L': return std::make_unique<MarketParticipantPositionMessage>(rawData);
        case 'V': return std::make_unique<MwcbDeclineLevelMessage>(rawData);
        case 'W': return std::make_unique<MwcbStatusMessage>(rawData);
        case 'K': return std::make_unique<IpoQuotingPeriodUpdateMessage>(rawData);
        case 'J': return std::make_unique<LuldAuctionCollarMessage>(rawData);
        case 'h': return std::make_unique<OperationalHaltMessage>(rawData);
        case 'A': return std::make_unique<AddOrderNoMpidMessage>(rawData);
        case 'F': return std::make_unique<AddOrderMpidAttributionMessage>(rawData);
        case 'E': return std::make_unique<OrderExecutedMessage>(rawData);
        case 'C': return std::make_unique<OrderExecutedWithPriceMessage>(rawData);
        case 'X': return std::make_unique<OrderCancelMessage>(rawData);
        case 'D': return std::make_unique<OrderDeleteMessage>(rawData);
        case 'U': return std::make_unique<OrderReplaceMessage>(rawData);
        case 'P': return std::make_unique<TradeMessage>(rawData);
        case 'Q': return std::make_unique<CrossTradeMessage>(rawData);
        case 'B': return std::make_unique<BrokenTradeMessage>(rawData);
        case 'I': return std::make_unique<NoiiMessage>(rawData);
        case 'N': return std::make_unique<RpiiMessage>(rawData);
        case 'O': return std::make_unique<DirectListingWithCapitalRaiseMessage>(rawData);
        default: throw std::logic_error{"Unknown message type"};
    }
    std::unreachable();
}
