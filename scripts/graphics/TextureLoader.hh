#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class TextureLoader {
    public:
        TextureLoader();
    private:
        const std::string route = "../res/";
        sf::Texture texture;
};