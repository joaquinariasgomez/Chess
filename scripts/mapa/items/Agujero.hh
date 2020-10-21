#pragma once
#include "Item.hh"

class Agujero: public Item {
    public:
        Agujero(int fila, int columna);
        void draw(sf::RenderWindow& window) const;
};