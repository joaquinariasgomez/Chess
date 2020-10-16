#include "Accion.hh"
#include "tablero/EstadoInicial.hh"

Accion::Accion(std::string movimiento) {
    //Adivinar celda y direccion desde movimiento
    char mov_array[movimiento.length() + 1];
    std::strcpy(mov_array, movimiento.c_str());
    celdaX = mov_array[0] - '0' - 1;
    celdaY = mov_array[1] - '0' - 1;
    direccion = mov_array[2];
}

int Accion::move(Tablero& t) const {
    int error = 0;
    //Comprobar que celda existe y que tiene una ficha en ella
    if(celdaX < 0 || celdaY < 0 || celdaX >= t.getDimension() || celdaY >= t.getDimension()) return -1;
    if(t.getCelda(celdaX, celdaY)->getFicha() != NULL) {    //Hay una ficha en esa posición
        //Comprobar que se pueda mover en esa dirección
        const Celda* celdaActual = t.getCelda(celdaX, celdaY);
        switch(direccion) {
            case 'w':
                if(celdaX != 0) {
                    if(t.getCelda(celdaX - 1, celdaY)->getFicha() == NULL) {
                        t.celdas[{celdaX, celdaY}] = t.getCelda(celdaX - 1, celdaY);
                        t.celdas[{celdaX - 1, celdaY}] = celdaActual;
                    } else {error = -1;}
                } else {error = -1;} break;
            case 'a':
                if(celdaY != 0) {
                    if(t.getCelda(celdaX, celdaY - 1)->getFicha() == NULL) {
                        t.celdas[{celdaX, celdaY}] = t.getCelda(celdaX, celdaY - 1);
                        t.celdas[{celdaX, celdaY - 1}] = celdaActual;
                    } else {error = -1;}
                } else {error= -1;} break;
            case 's':
                if(celdaX != (t.getDimension() - 1)) {
                    if(t.getCelda(celdaX + 1, celdaY)->getFicha() == NULL) {
                        t.celdas[{celdaX, celdaY}] = t.getCelda(celdaX + 1, celdaY);
                        t.celdas[{celdaX + 1, celdaY}] = celdaActual;
                    } else {error = -1;}
                } else {error = -1;} break;
            case 'd':
                if(celdaY != (t.getDimension() - 1)) {
                    if(t.getCelda(celdaX, celdaY + 1)->getFicha() == NULL) {
                        t.celdas[{celdaX, celdaY}] = t.getCelda(celdaX, celdaY + 1);
                        t.celdas[{celdaX, celdaY + 1}] = celdaActual;
                    } else {error = -1;}
                } else {error = -1;} break;
            default: return -1;
        }
    }
    else {error = -1;}
    return error;
}