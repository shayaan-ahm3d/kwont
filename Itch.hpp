#ifndef KWONT_ITCH_HPP
#define KWONT_ITCH_HPP

#include <filesystem>
#include <vector>
#include "messages/Message.hpp"

class Itch {
   public:
    std::vector<std::unique_ptr<Message>> exchangeMessages {};

    explicit Itch(std::filesystem::path itchFilepath);
};
#endif  // KWONT_ITCH_HPP
