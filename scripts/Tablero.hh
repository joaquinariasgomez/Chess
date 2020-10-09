#pragma once
#include "Celda.hh"
#include <iostream>
#include <map>
#include <utility>
#include "EstadoInicial.hh"

class Tablero {
    public:
        Tablero();
        friend std::ostream &operator<<(std::ostream &os, Tablero &obj) {return obj.printObject(os);}
    private:
        const int dimension_ = 8;
        std::map<std::pair<int, int>, const Celda*> celdas;
        std::ostream &printObject(std::ostream &os);
};