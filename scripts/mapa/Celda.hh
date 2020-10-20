#pragma once
#include <iostream>
#include "items/Item.hh"
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class Celda {
    public:
        Celda(int fila, int columna, int itemValor);
        void draw(sf::RenderWindow& window) const;
        Item* getItem() const {return item;}
        void setItem(Item* item2) {item=item2;}
    private:
        int fila_;
        int columna_;
        Item* item;
        SpriteManager* sprite;
};