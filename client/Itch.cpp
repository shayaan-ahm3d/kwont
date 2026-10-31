#include "Itch.hpp"

#include <utility>
#include <fstream>
#include <iostream>

#define ZMQ_BUILD_DRAFT_API
#include <zmq.hpp>

#include "../messages/MessageFactory.hpp"

Itch::Itch(const std::string_view address) {
    zmq::context_t context{};
    zmq::socket_t subscriber{context, zmq::socket_type::sub};
    subscriber.connect(address.data());

    while (exchangeMessages.size() < 10) {
        std::cout << "Num of Exchange Messages: " << exchangeMessages.size() << std::endl;
        zmq::message_t message;
        auto result = subscriber.recv(message, zmq::recv_flags::none);
        std::cout << "Result: " << result.value() << std::endl;
        auto exchangeMessage = MessageFactory::create(static_cast<const char*>(message.data()));
        std::cout << "Message Type: " << exchangeMessage->messageType << std::endl;
        exchangeMessages.emplace_back(std::move(exchangeMessage));
    }
    subscriber.close();
    zmq_ctx_destroy(&context);
}
