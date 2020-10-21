#pragma once
#include "Item.hh"
#include "../../entities/Player.hh"

class Pincho: public Item {
    public:
        Pincho(int fila, int columna, int gravedad);
        void draw(sf::RenderWindow& window) const;
        void hurt(Player& player);
        int getGravedad() const {return gravedad;}
    private:
        int gravedad;
};