#pragma once
#include <iostream>
#include "items/Item.hh"
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class Celda {
    public:
        Celda(int fila, int columna, int itemValor);
        void draw(sf::RenderWindow& window) const;
        const Item* getItem() const {return item;}
    private:
        int fila_;
        int columna_;
        Item* item;
        SpriteManager* sprite;
};