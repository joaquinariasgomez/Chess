#pragma once
#include "Item.hh"
#include "../Mapa.hh"
#include <string>

class Roca: public Item {
    public:
        Roca(int fila, int columna);
        void draw(sf::RenderWindow& window) const;
        int move(Mapa& mapa, std::string direction);
    private:
        int moveLeft(Mapa& mapa);
        int moveRight(Mapa& mapa);
        int moveUp(Mapa& mapa);
        int moveDown(Mapa& mapa);
        void updateSpritePosition();
        int checkItem(Mapa& mapa, Item* objItem, int desiredFila, int desiredColumna);
        int spriteState;    // Display a different texture depending on this internal state
};