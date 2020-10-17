#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class TextureLoader {
    public:
        TextureLoader(std::string textureName);
        sf::Texture getTexture() const;
    private:
        const std::string route = "../res/";
        sf::Texture texture;
};