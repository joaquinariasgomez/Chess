#include "TextureLoader.hh"

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