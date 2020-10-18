#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class TextureLoader {
    public:
        static sf::Texture getTexture(std::string textureName);
};

sf::Texture TextureLoader::getTexture(std::string textureName) {
    const std::string ROUTE = "../res/";
    sf::Texture texture;
    if (!texture.loadFromFile(ROUTE+textureName+".png"))
    {
        std::cout << "ERROR could not open texture " << textureName << std::endl;
    }

    //Texture properties
    texture.setSmooth(false);

    return texture;
}