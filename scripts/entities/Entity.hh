#pragma once
#include "../graphics/sprites/ItemSprite.hh"
#include <SFML/Graphics.hpp>

class Entity {
    protected:
        Entity(float vida, std::string textureName, int fila, int columna, int mapDimension): vida(vida), fila(fila), columna(columna), sprite(new ItemSprite(textureName, fila, columna, mapDimension)) {}
        float vida;
        ItemSprite* sprite;
        int fila;
        int columna;
        int mapDimension;
    public:
        virtual void draw(sf::RenderWindow& window) const = 0;
        virtual ~Entity() {}
        virtual void hurt(float damage) = 0;
};
