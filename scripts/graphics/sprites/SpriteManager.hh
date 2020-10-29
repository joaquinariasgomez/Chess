#pragma once
#include <SFML/Graphics.hpp>
//#include "../TextureLoader.hh"
//#include "../../mapa/Mapa.hh"

class SpriteManager {
    protected:
        SpriteManager(std::string textureName): textureName(textureName) {}
        std::string textureName;
        sf::Sprite sprite;
        sf::Texture texture;
    public:
        sf::Sprite getSprite() const {return sprite;}
};