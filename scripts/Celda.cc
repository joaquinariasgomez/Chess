#include "Celda.hh"

Celda::Celda(int fila, int columna, int valorCelda): fila_(fila), columna_(columna) {
    switch(valorCelda) {
        case 1: ficha = new FichaO(); break;
        case 2: ficha = new FichaX(); break;
        case -1:
        default: ficha = NULL;
    }
}

std::string Celda::print() const {
    if(ficha == NULL) return " ";
    return ficha->print();
}