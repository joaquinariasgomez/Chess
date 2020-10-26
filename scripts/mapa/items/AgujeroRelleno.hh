#pragma once
#include "Item.hh"

class AgujeroRelleno: public Item {
    public:
        AgujeroRelleno(int fila, int columna, int mapDimension);
        void draw(sf::RenderWindow& window) const;
};