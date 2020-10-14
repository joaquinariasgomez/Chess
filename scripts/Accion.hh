#pragma once
#include "tablero/Tablero.hh"

class Accion {
    public:
        Accion(std::string movimiento);
        void move(Tablero& t) const;
    private:
        int celdaX;
        int celdaY;
        char direccion;
};