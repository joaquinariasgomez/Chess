#include "ItemSprite.hh"
#include "../TextureLoader.hh"
#include "../Window.hh"

ItemSprite::ItemSprite(std::string textureName, int fila, int columna, int mapDimension): mapDimension(mapDimension), SpriteManager(textureName) {
    texture = TextureLoader::getTexture(textureName);
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    //Sprite properties
    float spriteWidth = (float)Window::getMapWidth() / (float)mapDimension;
    float spriteHeight = (float)Window::getMapHeight() / (float)mapDimension;
    sprite.setPosition(sf::Vector2f(columna * spriteHeight, fila * spriteWidth + Window::getBarHeight()));
    sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
}

void ItemSprite::updateTexture(std::string textureName) {
    texture = TextureLoader::getTexture(textureName);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    // Sprite properties
    float spriteWidth = (float)Window::getMapWidth() / (float)mapDimension;
    float spriteHeight = (float)Window::getMapHeight() / (float)mapDimension;
    sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
}

void ItemSprite::updatePosition(int fila, int columna) {
    float spriteWidth = (float)Window::getMapWidth() / (float)mapDimension;
    float spriteHeight = (float)Window::getMapHeight() / (float)mapDimension;
    sprite.setPosition(sf::Vector2f(columna * spriteHeight, fila * spriteWidth + Window::getBarHeight()));
}