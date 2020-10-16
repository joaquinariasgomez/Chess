#pragma once
#include "Celda.hh"
#include <iostream>
#include <map>
#include <utility>

class Tablero {
    public:
        Tablero();
        friend std::ostream &operator<<(std::ostream &os, Tablero &obj) {return obj.printObject(os);}
        const int getDimension() const {return dimension_;}
        const Celda* getCelda(int x, int y) {return celdas[{x,y}];}

        std::map<std::pair<int, int>, const Celda*> celdas;
    private:
        const int dimension_ = 8;
        std::ostream &printObject(std::ostream &os);
};