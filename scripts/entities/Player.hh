#pragma once
#include "../graphics/sprites/ItemSprite.hh"
#include <SFML/Graphics.hpp>
#include "../mapa/Level.hh"
#include "../mapa/StatusBar.hh"
#include "../weapons/Arma.hh"

class Player {
    public:
        enum EventType {
            NONE,
            MOVE,
            CHANGE_WEAPON,
            ATTACK_DEFEND
        };
        Player(Level* level);
        EventType evaluateEvent(sf::Event event, Level& level);
        void draw(sf::RenderWindow& window) const;
        void hurt(float damage);
        Arma* getWeapon() const;
        int getFila() const;
        int getColumna() const;
    private:
        bool moveLeft(Level& level);
        bool moveRight(Level& level);
        bool moveUp(Level& level);
        bool moveDown(Level& level);
        EventType evaluateLeft(Level& level);
        EventType evaluateRight(Level& level);
        EventType evaluateUp(Level& level);
        EventType evaluateDown(Level& level);
        void attackRight(Level& level);
        void attackLeft(Level& level);
        void attackUp(Level& level);
        void attackDown(Level& level);

        void updateSpritePosition();
        bool checkItem(Level& level, Item* objItem, int desiredFila, int desiredColumna);
        void changeWeapon();
        float getVida() const;
        
        void checkCeldaObjetivo(Level& level) const;
        void die();
        int currentArma;
        std::vector<Arma*> armas; // 0 -> No arma, 1,2 -> Espada, Escudo
        int fila;
        int columna;
        ItemSprite* sprite;  //player sprite
        StatusBar* statusBar;
        int score;
};
