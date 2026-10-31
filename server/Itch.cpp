#include "Itch.hpp"

#include <fstream>
#include <iostream>

#define ZMQ_BUILD_DRAFT_API
#include <zmq.hpp>

#include "../messages/Message.hpp"

Itch::Itch(const std::filesystem::path& itchFilepath) {
    zmq::context_t context{};
    zmq::socket_t exchangePublisher{context, zmq::socket_type::pub};
    exchangePublisher.bind("tcp://localhost:6767");

    if (std::ifstream itchFile{itchFilepath, std::ifstream::binary}) {
        itchFile.seekg(0, std::ifstream::end);
        const int fileSize = itchFile.tellg();
        itchFile.seekg(0, std::ifstream::beg);

        constexpr size_t GIGA = 1000;
        char* const buffer = new char[GIGA];
        itchFile.read(buffer, GIGA);

        char* filePtr = buffer;

        while (filePtr < buffer + GIGA - BYTES_FOR_SIZE) {
            const size_t size = (filePtr[0] << BITS_PER_BYTE) | filePtr[1];
            filePtr += BYTES_FOR_SIZE;

            zmq::message_t msg{filePtr, size};
            auto result = exchangePublisher.send(msg, zmq::send_flags::none);
            std::cout << "Result: " << result.value() << std::endl;

            sleep(1);
            if (filePtr + size < buffer + GIGA) {
                // jump forward by the size of the message
                filePtr += size;
                std::cout << "Size: " << size << " B\n";
            } else {
                break;
            }
        }

        delete[] buffer;
    }
    exchangePublisher.close();
    zmq_ctx_destroy(&context);
}