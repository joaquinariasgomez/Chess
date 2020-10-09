#pragma once
#include <iostream>

class Celda {
    public:
        Celda(int fila, int columna): fila_(fila), columna_(columna) {}
        //Celda(const Celda&) = default;
        //friend std::ostream &operator<<(std::ostream &os, Celda &obj) {return obj.printObject(os);}
        std::string print() const;
    private:
        int fila_;
        int columna_;
};