set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGES CXX)
add_library(estadoInicial
    STATIC
        scripts/tablero/EstadoInicial.hh
        scripts/tablero/EstadoInicial.cc
    )
add_library(accion
    STATIC
        scripts/Accion.hh
        scripts/Accion.cc
    )
add_library(tablero
    STATIC
        scripts/tablero/Tablero.hh
        scripts/tablero/Tablero.cc
    )
add_library(celda
    STATIC
        scripts/tablero/Celda.hh
        scripts/tablero/Celda.cc
    )
add_library(ficha
    STATIC
        scripts/tablero/Ficha.hh
        scripts/tablero/Ficha.cc
    )
add_library(fichaO
    STATIC
        scripts/tablero/FichaO.hh
        scripts/tablero/FichaO.cc
    )
add_library(fichaX
    STATIC
        scripts/tablero/FichaX.hh
        scripts/tablero/FichaX.cc
    )
add_executable(main scripts/main.cc)
target_link_libraries(accion tablero)
target_link_libraries(tablero estadoInicial)
target_link_libraries(tablero celda)
target_link_libraries(celda ficha)
target_link_libraries(ficha fichaO)
target_link_libraries(ficha fichaX)
target_link_libraries(main tablero)
target_link_libraries(main accion)
