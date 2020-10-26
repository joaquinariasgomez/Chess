#pragma once
#include <SFML/Graphics.hpp>

class SpriteManager {
    public:
        SpriteManager(int fila, int columna, std::string textureName, int mapDimension, bool weapon=false);  // Map
        SpriteManager(std::string textureName);  // StatusBar
        sf::Sprite getSprite() const;
        void updatePosition(int fila, int columna);
        void updateTexture(std::string textureName);
        void updateLife(float life);
    private:
        void renderWeapon(int fila, int columna);
        void renderLife(float life);
        void renderNoLife();
        void renderLifeCover();
        sf::Sprite sprite;
        sf::Texture texture;
        int mapDimension;
};