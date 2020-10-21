#pragma once
#include "../../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class Item {
    protected:
        Item(int fila, int columna, std::string texture, int id): fila(fila), columna(columna), sprite(new SpriteManager(fila, columna, texture)), id(id) {}
        SpriteManager* sprite;
        int fila;
        int columna;
    public:
        virtual void draw(sf::RenderWindow& window) const = 0;
        virtual ~Item() {}
        int id;
};