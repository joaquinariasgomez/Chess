#pragma once
#include "tablero/Tablero.hh"

class Accion {
    public:
        Accion(std::string movimiento);
        int move(Tablero& t) const;
    private:
        int celdaX;
        int celdaY;
        char direccion;
};