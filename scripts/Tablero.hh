#pragma once
#include "Celda.hh"
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
    private:
        std::vector<const Celda*> celdas;
        int dimension_;
};