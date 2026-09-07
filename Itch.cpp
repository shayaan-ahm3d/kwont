#include <fstream>
#include <utility>

#include "Itch.hpp"

#include <iostream>
#include "messages/MessageFactory.hpp"

Itch::Itch(const std::filesystem::path& itchFilepath) {
    if (std::ifstream itchFile{itchFilepath, std::ifstream::binary}) {
        itchFile.seekg(0, std::ifstream::end);
        const int fileSize = itchFile.tellg();
        itchFile.seekg(0, std::ifstream::beg);

        char* const buffer = new char[fileSize];
        itchFile.read(buffer, fileSize);

        char* filePtr = buffer;

        while (filePtr < buffer + fileSize - BYTES_FOR_SIZE and exchangeMessages.size() < 10) {
            const int size = (filePtr[0] << BITS_PER_BYTE) | filePtr[1];
            filePtr += BYTES_FOR_SIZE;
            if (filePtr + size < buffer + fileSize) {
                auto message = MessageFactory::create(filePtr);
                // jump forward by the size of the message
                filePtr += size;
                //std::cout << message->messageType << "\n";
                exchangeMessages.emplace_back(std::move(message)); // move after accessing messageType so no nullptr
                std::cout << "size: " << filePtr-buffer << "\n";
            } else {
                break;
            }
        }

        delete[] buffer;
    }
}
