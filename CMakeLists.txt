set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGES CXX)
add_library(estadoInicial
    STATIC
        scripts/EstadoInicial.hh
        scripts/EstadoInicial.cc
    )
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
add_library(ficha
    STATIC
        scripts/Ficha.hh
        scripts/Ficha.cc
    )
add_library(fichaO
    STATIC
        scripts/FichaO.hh
        scripts/FichaO.cc
    )
add_library(fichaX
    STATIC
        scripts/FichaX.hh
        scripts/FichaX.cc
    )
add_executable(main scripts/main.cc)
target_link_libraries(tablero estadoInicial)
target_link_libraries(tablero celda)
target_link_libraries(celda ficha)
target_link_libraries(ficha fichaO)
target_link_libraries(ficha fichaX)
target_link_libraries(main tablero)
