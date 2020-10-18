#pragma once
#include <iostream>
#include "FichaO.hh"
#include "FichaX.hh"

class Celda {
    public:
        Celda(int fila, int columna, int valorCelda);
        std::string print() const;
        const Ficha* getFicha() const {return ficha;}
    private:
        int fila_;
        int columna_;
        Ficha* ficha;
};