#include "TextureLoader.hh"
#include <iostream>

TextureLoader::TextureLoader(std::string textureName) {
    if (!texture.loadFromFile(route+textureName+".png"))
    {
        // error...
        std::cout << "ERROR no se ha podido leer la imagen" << std::endl;
    }
}

sf::Texture TextureLoader::getTexture() const {
    return texture;
}