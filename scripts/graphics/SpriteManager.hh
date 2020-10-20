#pragma once
#include <SFML/Graphics.hpp>

class SpriteManager {
    public:
        SpriteManager(int posX, int posY, std::string textureName);
        sf::Sprite getSprite() const;
    private:
        int posX;
        int posY;
        sf::Sprite sprite;
        sf::Texture texture;
};