cmake_minimum_required(VERSION 4.3)
project(kwont)

include(FetchContent)
FetchContent_Declare(
  frozen
  GIT_REPOSITORY https://github.com/serge-sans-paille/frozen.git
  GIT_TAG b07a5c8187bc3e6f1461efab89fe07f467e300db
)
FetchContent_MakeAvailable(frozen)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(kwont
  Main.cpp
  Itch.cpp
  Itch.hpp
  messages/Message.cpp
  messages/Message.hpp
  messages/SystemEventMessage.cpp
  messages/SystemEventMessage.hpp
  messages/StockDirectoryMessage.cpp
  messages/StockDirectoryMessage.hpp
  messages/StockTradingActionMessage.cpp
  messages/StockTradingActionMessage.hpp
  messages/RegShoRestrictionMessage.cpp
  messages/RegShoRestrictionMessage.hpp
  messages/MarketParticipantPositionMessage.cpp
  messages/MarketParticipantPositionMessage.hpp
  messages/MwcbDeclineLevelMessage.cpp
  messages/MwcbDeclineLevelMessage.hpp
  messages/MwcbStatusMessage.cpp
  messages/MwcbStatusMessage.hpp
  messages/IpoQuotingPeriodUpdateMessage.cpp
  messages/IpoQuotingPeriodUpdateMessage.hpp
  messages/OperationalHaltMessage.cpp
  messages/OperationalHaltMessage.hpp
  messages/LuldAuctionCollarMessage.cpp
  messages/LuldAuctionCollarMessage.hpp
  messages/AddOrderNoMpidMessage.cpp
  messages/AddOrderNoMpidMessage.hpp
  messages/AddOrderMpidAttributionMessage.cpp
  messages/AddOrderMpidAttributionMessage.hpp
  messages/MarketParticipantPositionMessage.cpp
  messages/MarketParticipantPositionMessage.hpp
  messages/OrderCancelMessage.cpp
  messages/OrderCancelMessage.hpp
  messages/OrderDeleteMessage.cpp
  messages/OrderDeleteMessage.hpp
  messages/OrderExecutedMessage.cpp
  messages/OrderExecutedMessage.hpp
  messages/OrderExecutedWithPriceMessage.cpp
  messages/OrderExecutedWithPriceMessage.hpp
  messages/OrderReplaceMessage.cpp
  messages/OrderReplaceMessage.hpp
  messages/TradeMessage.cpp
  messages/TradeMessage.hpp
  messages/CrossTradeMessage.cpp
  messages/CrossTradeMessage.hpp
  messages/BrokenTradeMessage.cpp
  messages/BrokenTradeMessage.hpp
  messages/MessageFactory.cpp
  messages/MessageFactory.hpp
  messages/NoiiMessage.cpp
  messages/NoiiMessage.hpp
  messages/RpiiMessage.cpp
  messages/RpiiMessage.hpp
  messages/DirectListingWithCapitalRaiseMessage.cpp
  messages/DirectListingWithCapitalRaiseMessage.hpp
)

target_link_libraries(kwont PRIVATE frozen::frozen)

target_compile_options(kwont PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -fsanitize=address,undefined
  -funsigned-char
)

target_link_options(kwont PRIVATE
  -fsanitize=address,undefined
)
