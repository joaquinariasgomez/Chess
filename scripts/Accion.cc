#include "Accion.hh"

Accion::Accion(std::string movimiento) {
    //Adivinar celda y direccion desde movimiento
    char mov_array[movimiento.length() + 1];
    std::strcpy(mov_array, movimiento.c_str());
    celdaX = mov_array[0] - '0' - 1;
    celdaY = mov_array[1] - '0' - 1;
    direccion = mov_array[2];
}

void Accion::move(Tablero& t) const {

}