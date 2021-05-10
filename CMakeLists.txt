cmake_minimum_required(VERSION 3.19)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp Square.h Ship.h Player.h Square.cpp Ship.cpp Player.cpp Game.h Game.cpp)