cmake_minimum_required(VERSION 4.3)
project(kwont)

set(CMAKE_CXX_STANDARD 26)

add_executable(kwont
        Main.cpp
        Itch.cpp
        Itch.hpp
        Message.cpp
        Message.hpp
        SystemEventMessage.cpp
        SystemEventMessage.hpp)
