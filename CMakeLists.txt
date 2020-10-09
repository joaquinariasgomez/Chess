set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGES CXX)
add_library(tablero
    STATIC
        scripts/Tablero.hh
        scripts/Tablero.cc
    )
add_library(celda
    STATIC
        scripts/Celda.hh
        scripts/Celda.cc
    )
add_executable(main scripts/main.cc)
target_link_libraries(tablero celda)
target_link_libraries(main tablero)
