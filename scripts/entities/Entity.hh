#pragma once
#include "../graphics/sprites/ItemSprite.hh"
#include <SFML/Graphics.hpp>

class Player;

class Entity {
    protected:
        Entity(float vida, std::string textureName, int fila, int columna, int mapDimension): vida(vida), fila(fila), columna(columna), sprite(new ItemSprite(textureName, fila, columna, mapDimension)) {}
        float vida;
        ItemSprite* sprite;
        int mapDimension;
    public:
        int fila;
        int columna;
        virtual void draw(sf::RenderWindow& window) const = 0;
        virtual void hurt(float damage) = 0;
        virtual bool isDead() const = 0;
        virtual void update(Player& player) = 0;
        virtual ~Entity() {}
};
