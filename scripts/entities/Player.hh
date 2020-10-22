#pragma once
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>
#include "../mapa/Mapa.hh"
#include "../mapa/StatusBar.hh"

class Player {
    public:
        Player(StatusBar* statusBar);
        void draw(sf::RenderWindow& window) const;
        void evaluateEvent(sf::Event event, Mapa& mapa);
        void hurt(int damage);
        int getVida() const {return vida;}
        static float maxVida;
    private:
        void moveUp(Mapa& mapa);
        void moveDown(Mapa& mapa);
        void moveRight(Mapa& mapa);
        void moveLeft(Mapa& mapa);
        void updateSpritePosition();
        void checkItem(Mapa& mapa, Item* objItem, int desiredFila, int desiredColumna);
        int fila;
        int columna;
        SpriteManager* sprite;  //player sprite
        float vida;
        StatusBar* statusBar;
};