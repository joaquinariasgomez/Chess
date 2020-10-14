#include <iostream>
#include "tablero/Tablero.hh"
#include "Accion.hh"

int main() {
    Tablero tablero;
    while(true) {
        // Printear tablero
        std::cout << tablero << std::endl;
        // Leer acción
        std::string mov;
        std::cin >> mov;
        
        // Crear acción que contiene a tablero
        Accion accion(mov);
        accion.move(tablero);
    }
}