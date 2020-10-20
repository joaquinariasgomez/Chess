#pragma once
#include "../../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class Item {
    protected:
        Item(int fila, int columna, std::string texture): sprite(new SpriteManager(fila, columna, texture)) {}
        SpriteManager* sprite;
    public:
        virtual void draw(sf::RenderWindow& window) const = 0;
        virtual ~Item() {}
};