#include <print>

#include "Itch.hpp"

int main() {
    const std::filesystem::path itchFilepath{"data/2020-01-30.NASDAQ_ITCH50"};
    Itch data{itchFilepath};
    std::println("Hello, World");
}
