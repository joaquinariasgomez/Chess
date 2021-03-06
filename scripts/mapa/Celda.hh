#pragma once
#include <iostream>
#include "items/Item.hh"
#include "../graphics/sprites/ItemSprite.hh"
#include <SFML/Graphics.hpp>

class Celda {
    public:
        Celda(int fila, int columna, int mapDimension, int itemValor, bool objetivo = false);
        void draw(sf::RenderWindow& window) const;
        Item* getLastItem() const {return items.back();}
        void pushItem(Item* item) {items.push_back(item);}
        void removeItem(Item* item);
        void updateSpriteTexture(std::string textureName);
    private:
        int fila_;
        int columna_;
        std::vector<Item*> items;
        ItemSprite* sprite;
};
