set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(myGame LANGUAGES CXX)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

file(GLOB SOURCES
    "scripts/*.hh"
    "scripts/*.cc"
    "scripts/tablero/*.hh"
    "scripts/tablero/*.cc"
    "scripts/graphics/*.hh"
    "scripts/graphics/*.cc"
)

add_executable(myGame ${SOURCES})
target_link_libraries(myGame sfml-graphics sfml-window sfml-system)
