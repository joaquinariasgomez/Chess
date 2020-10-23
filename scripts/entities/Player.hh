#pragma once
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>
#include "../mapa/Mapa.hh"
#include "../mapa/StatusBar.hh"
#include "../weapons/Arma.hh"

class Player {
    public:
        Player(StatusBar* statusBar);
        void evaluateEvent(sf::Event event, Mapa& mapa);
        static float maxVida;
        void draw(sf::RenderWindow& window) const;
        float getVida() const {return vida;}
        void hurt(int damage);
    private:
        void moveLeft(Mapa& mapa);
        void moveRight(Mapa& mapa);
        void moveUp(Mapa& mapa);
        void moveDown(Mapa& mapa);
        void updateSpritePosition();
        void checkItem(Mapa& mapa, Item* objItem, int desiredFila, int desiredColumna);
        void changeWeapon();
        Arma* currentArma;
        std::vector<Arma*> armas;
        int armaId; // 0 -> No arma, 1,2 -> Espada, Escudo
        int fila;
        int columna;
        SpriteManager* sprite;  //player sprite
        float vida;
        StatusBar* statusBar;
};