#pragma once
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>
#include "../mapa/Level.hh"
#include "../mapa/StatusBar.hh"
#include "../weapons/Arma.hh"

class Player {
    public:
        Player(StatusBar* statusBar);
        //void evaluateEvent(sf::Event event, Mapa& mapa);
        void evaluateEvent(sf::Event event, Level& level);
        static float maxVida;
        void draw(sf::RenderWindow& window) const;
        float getVida() const {return vida;}
        void hurt(int damage);
        Arma* getWeapon() const;
    private:
        void moveLeft(Level& level);
        void moveRight(Level& level);
        void moveUp(Level& level);
        void moveDown(Level& level);
        void evaluateLeft(Level& level);
        void evaluateRight(Level& level);
        void evaluateUp(Level& level);
        void evaluateDown(Level& level);

        void updateSpritePosition();
        void checkItem(Level& level, Item* objItem, int desiredFila, int desiredColumna);
        void changeWeapon();
        int currentArma;
        std::vector<Arma*> armas; // 0 -> No arma, 1,2 -> Espada, Escudo
        int fila;
        int columna;
        SpriteManager* sprite;  //player sprite
        float vida;
        StatusBar* statusBar;
};