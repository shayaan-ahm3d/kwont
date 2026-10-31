#include "AddOrderMpidAttributionMessage.hpp"
#include "AddOrderNoMpidMessage.hpp"

AddOrderMpidAttributionMessage::AddOrderMpidAttributionMessage(const std::span<const char> rawData) : AddOrderNoMpidMessage(rawData){
    attribution = {&rawData.at(36), 4};
}
