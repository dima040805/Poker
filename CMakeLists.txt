cmake_minimum_required(VERSION 3.16)
project(Poker CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(poker
        main.cpp
        bet.cpp
        win.cpp
        "game table.cpp")
target_include_directories(poker PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
