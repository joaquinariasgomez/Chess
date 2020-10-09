#pragma once
#include "Celda.hh"
#include <iostream>
#include <vector>

class Tablero {
    public:
        Tablero(): dimension_(8) {
            for(int i=0; i<dimension_; ++i) {
                for(int j=0; j<dimension_; ++j) {
                    celdas.push_back(new Celda(i, j));
                }
            }
        }

        friend std::ostream &operator<<(std::ostream &os, Tablero &obj) {
            return obj.printObject(os);
        }
    private:
        std::vector<const Celda*> celdas;
        int dimension_;
        std::ostream &printObject(std::ostream &os);
};