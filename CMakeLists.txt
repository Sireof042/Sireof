cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build shared library" ON)

add_library(gamelib
    gamelib/board.cpp
    gamelib/game.cpp
    gamelib/history.cpp
    gamelib/menu.cpp
    gamelib/params.cpp
)

target_include_directories(gamelib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/gamelib)

add_executable(TicTacToe main.cpp)

target_link_libraries(TicTacToe PRIVATE gamelib)