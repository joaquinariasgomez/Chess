#pragma once
#include "Item.hh"

class Pared: public Item {
    public:
        Pared(int fila, int columna, int mapDimension);
        void draw(sf::RenderWindow& window) const;
};