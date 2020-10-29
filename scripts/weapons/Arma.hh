#pragma once
#include "../graphics/sprites/ItemSprite.hh"
#include <SFML/Graphics.hpp>

class Arma {
    protected:
        Arma(int fila, int columna, int mapDimension, std::string texture, int id): fila(fila), columna(columna), sprite(new ItemSprite(texture, fila, columna, mapDimension)), id(id) {}
        ItemSprite* sprite;
        int fila;
        int columna;
    public:
        virtual void draw(sf::RenderWindow& window) const = 0;
        virtual void updatePosition(int fila, int columna) = 0;
        ItemSprite* getSprite() {return sprite;}
        virtual ~Arma() {}
        int id; // 1 -> Espada
                // 2 -> Escudo
};
