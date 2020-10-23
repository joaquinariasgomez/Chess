#pragma once
#include "Arma.hh"

class Espada: public Arma {
    public:
        Espada(int fila, int columna);
        void draw(sf::RenderWindow& window) const;
        void updatePosition(int fila, int columna);
    private:
        int bloodAmount;    // Cantidad de sangre en la espada: 0 -> 4
};