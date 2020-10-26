#pragma once
#include "../../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class Item {
    protected:
        Item(int fila, int columna, int mapDimension, std::string texture, int id): fila(fila), columna(columna), mapDimension(mapDimension), sprite(new SpriteManager(fila, columna, texture, mapDimension)), id(id) {}
        SpriteManager* sprite;
        int fila;
        int columna;
        int mapDimension;
    public:
        virtual void draw(sf::RenderWindow& window) const = 0;
        virtual ~Item() {}
        int id;
};