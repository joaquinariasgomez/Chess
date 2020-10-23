#pragma once
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class Arma {
    protected:
        Arma(int fila, int columna, std::string texture, int id): fila(fila), columna(columna), sprite(new SpriteManager(fila, columna, texture, true)), id(id) {}
        SpriteManager* sprite;
        int fila;
        int columna;
    public:
        virtual void draw(sf::RenderWindow& window) const = 0;
        virtual void updatePosition(int fila, int columna) = 0;
        SpriteManager* getSprite() {return sprite;}
        virtual ~Arma() {}
        int id; // 1 -> Espada
                // 2 -> Escudo
};