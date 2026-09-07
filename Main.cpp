#include <filesystem>

#include "Itch.hpp"

int main() {
    const std::filesystem::path curr = std::filesystem::current_path();
    const std::filesystem::path itchFilepath{curr / "../data/2020-01-30.NASDAQ_ITCH50"};
    Itch data{itchFilepath};
    return EXIT_SUCCESS;
}
