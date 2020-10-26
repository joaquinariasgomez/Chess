#pragma once
#include "Arma.hh"

class Escudo: public Arma {
    public:
        Escudo(int fila, int columna, int mapDimension);
        void draw(sf::RenderWindow& window) const;
        void updatePosition(int fila, int columna);
};