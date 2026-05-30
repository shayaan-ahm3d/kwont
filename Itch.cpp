#include <fstream>

#include "Itch.hpp"

Itch::Itch(std::filesystem::path itchFilepath) {
    std::ifstream itchFile{itchFilepath, std::ios::binary};
};
