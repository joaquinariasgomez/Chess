#pragma once
#include "../../graphics/sprites/ItemSprite.hh"
#include <SFML/Graphics.hpp>

class Item {
    protected:
        Item(int fila, int columna, int mapDimension, std::string texture, int id): fila(fila), columna(columna), mapDimension(mapDimension), sprite(new ItemSprite(texture, fila, columna, mapDimension)), id(id) {}
        ItemSprite* sprite;
        int fila;
        int columna;
        int mapDimension;
    public:
        virtual void draw(sf::RenderWindow& window) const = 0;
        virtual ~Item() {}
        int id;
};
