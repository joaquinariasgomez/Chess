#pragma once
#include "Item.hh"
#include "../Level.hh"
#include <string>

class Roca: public Item {
    public:
        Roca(int fila, int columna);
        void draw(sf::RenderWindow& window) const;
        int move(Level& level, std::string direction);
    private:
        int moveLeft(Level& level);
        int moveRight(Level& level);
        int moveUp(Level& level);
        int moveDown(Level& level);
        void updateSpritePosition();
        int checkItem(Level& level, Item* objItem, int desiredFila, int desiredColumna);
        void updateTexture(std::string direction);
        std::pair<int,int> spriteState;    // Display a different texture depending on this internal state
};