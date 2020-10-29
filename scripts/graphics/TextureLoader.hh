#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class TextureLoader {
    public:
        static sf::Texture getTexture(std::string textureName);
};