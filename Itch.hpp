#ifndef KWONT_ITCH_HPP
#define KWONT_ITCH_HPP

#include <filesystem>
#include <vector>
#include "Message.hpp"

class Itch {
public:
    std::vector<Message> exchangeMessages;

    explicit Itch(std::filesystem::path itchFilepath);
};
#endif //KWONT_ITCH_HPP
