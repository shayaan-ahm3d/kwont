#ifndef KWONT_ITCH_HPP
#define KWONT_ITCH_HPP

#include <filesystem>
#include <vector>
#include "messages/Message.hpp"

class Itch {
   public:
    std::vector<std::unique_ptr<Message>> exchangeMessages {}; // different message subclasses so need unique_ptr as would do dynamic dispatch in Java

    explicit Itch(const std::filesystem::path& itchFilepath);
};
#endif  // KWONT_ITCH_HPP
