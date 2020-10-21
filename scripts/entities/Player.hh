#pragma once
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>
#include "../mapa/Mapa.hh"

class Player {
    public:
        Player();
        void draw(sf::RenderWindow& window) const;
        void evaluateEvent(sf::Event event, Mapa& mapa);
        void hurt(int damage);
    private:
        void moveUp(Mapa& mapa);
        void moveDown(Mapa& mapa);
        void moveRight(Mapa& mapa);
        void moveLeft(Mapa& mapa);
        void updateSpritePosition();
        void checkItem(Mapa& mapa, Item* objItem, int desiredFila, int desiredColumna);
        int fila;
        int columna;
        SpriteManager* sprite;  //background sprite
        float vida;
};