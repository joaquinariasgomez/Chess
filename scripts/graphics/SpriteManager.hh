#pragma once
#include <SFML/Graphics.hpp>

class SpriteManager {
    public:
        SpriteManager(int fila, int columna, std::string textureName);
        sf::Sprite getSprite() const;
        void updatePosition(int fila, int columna);
    private:
        int fila;
        int columna;
        sf::Sprite sprite;
        sf::Texture texture;
};