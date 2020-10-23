#pragma once
#include "Arma.hh"

class Espada: public Arma {
    public:
        Espada(int fila, int columna);
        void draw(sf::RenderWindow& window) const;
};