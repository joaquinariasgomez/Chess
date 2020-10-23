#pragma once
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class Entity {
    protected:
        Entity(float vida): vida(vida) {}
        SpriteManager* sprite;
        int fila;
        int columna;
        float vida;
    public:
        virtual void draw(sf::RenderWindow& window) const = 0;
        virtual ~Entity() {}
        virtual float getVida() const;  //return vida
        virtual void hurt(int damage);
};