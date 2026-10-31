#ifndef SERVER_ITCH_HPP
#define SERVER_ITCH_HPP

#include <filesystem>

class Itch {
public:
    explicit Itch(const std::filesystem::path& itchFilepath);
};

#endif  // SERVER_ITCH_HPP