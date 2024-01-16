cmake_minimum_required(VERSION 3.26)
project(Poker)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Poker
        page header.h
        bet.cpp
        win.cpp
        game.cpp
        game table.cpp)
