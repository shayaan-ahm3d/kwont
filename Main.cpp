#include <filesystem>
#include <print>

#include "Itch.hpp"

int main() {
    std::filesystem::path curr = std::filesystem::current_path();
    std::filesystem::path itchFilepath{curr /
                                       "../data/2020-01-30.NASDAQ_ITCH50"};
    Itch data{itchFilepath};
}
