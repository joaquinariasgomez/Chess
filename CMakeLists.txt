set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(myGame LANGUAGES CXX)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

file(GLOB SOURCES
    "scripts/*.hh"
    "scripts/*.cc"
    "scripts/mapa/*.hh"
    "scripts/mapa/*.cc"
    "scripts/mapa/items/*.hh"
    "scripts/mapa/items/*.cc"
    "scripts/entities/*.hh"
    "scripts/entities/*.cc"
    "scripts/graphics/*.hh"
    "scripts/graphics/*.cc"
    "scripts/weapons/*.hh"
    "scripts/weapons/*.cc"
)

add_executable(myGame ${SOURCES})
target_link_libraries(myGame sfml-graphics sfml-window sfml-system)
