#include "IpoQuotingPeriodUpdateMessage.hpp"
#include "Message.hpp"

[[nodiscard]] static std::chrono::seconds parseIpoReleaseTime(const std::span<char> rawData) {
    uint32_t temp = rawData.at(19) << (3*BITS_PER_BYTE)
        | rawData.at(20) << (2*BITS_PER_BYTE)
        | rawData.at(21) << BITS_PER_BYTE
        | rawData.at(22);
    return std::chrono::seconds{temp};
}

IpoQuotingPeriodUpdateMessage::IpoQuotingPeriodUpdateMessage(const std::span<char> rawData) : Message(rawData) {
    stock = {&rawData.at(11), 8};
    ipoQuotationReleaseTime = parseIpoReleaseTime(rawData);
    ipoQuotationReleaseQualifier = static_cast<IpoQuotationReleaseQualifier>(rawData.at(23));
    price = rawData.at(24) << (3*BITS_PER_BYTE)
        | rawData.at(25) << (2*BITS_PER_BYTE)
        | rawData.at(26) << BITS_PER_BYTE
        | rawData.at(27);
}
