#include <fstream>
#include <utility>

#include "Itch.hpp"
#include "messages/MessageFactory.hpp"

Itch::Itch(std::filesystem::path itchFilepath) {
    std::ifstream itchFile{itchFilepath, std::ifstream::binary};
    if (itchFile) {
        itchFile.seekg(0, itchFile.end);
        const int fileSize = itchFile.tellg();
        itchFile.seekg(0, itchFile.beg);

        char* buffer = new char[fileSize];
        itchFile.read(buffer, fileSize);

        MessageFactory messageFactory;
        char* filePtr = buffer;

        while (filePtr <= buffer + fileSize) {
            // find valid message
            while (not charToMessageType.contains(*filePtr)) {
                filePtr++;
            }
            auto message = messageFactory.create(filePtr);
            exchangeMessages.emplace_back(std::move(message));
            filePtr += messageTypeToSize.at(std::to_underlying(message->messageType));
        }

        delete[] buffer;
    }
}
