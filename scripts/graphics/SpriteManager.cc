#include "SpriteManager.hh"
#include "TextureLoader.hh"
#include "../mapa/Mapa.hh"
#include "Window.hh"

SpriteManager::SpriteManager(int fila, int columna, std::string textureName): fila(fila), columna(columna) {
    texture = TextureLoader::getTexture(textureName);
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    //Sprite properties
    if(textureName == "background") {
        sprite.setPosition(sf::Vector2f(0, Window::getBarHeight()));
        sprite.setScale(sf::Vector2f((float)Window::getMapWidth()/(float)textureWidth, (float)Window::getMapHeight()/(float)textureHeight));
    }
    else {
        if(textureName == "statusBar") {

        }
        else {
            float spriteWidth = (float)Window::getMapWidth() / (float)Mapa::dimension;
            float spriteHeight = (float)Window::getMapHeight() / (float)Mapa::dimension;
            sprite.setPosition(sf::Vector2f(columna * spriteHeight, fila * spriteWidth + Window::getBarHeight()));
            sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
        }
    }
}

void SpriteManager::updatePosition(int fila, int columna) {
    float spriteWidth = (float)Window::getMapWidth() / (float)Mapa::dimension;
    float spriteHeight = (float)Window::getMapHeight() / (float)Mapa::dimension;
    sprite.setPosition(sf::Vector2f(columna * spriteHeight, fila * spriteWidth + Window::getBarHeight()));
}

sf::Sprite SpriteManager::getSprite() const {
    return sprite;
}

void SpriteManager::updateTexture(std::string textureName) {
    texture = TextureLoader::getTexture(textureName);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    float spriteWidth = (float)Window::getMapWidth() / (float)Mapa::dimension;
    float spriteHeight = (float)Window::getMapHeight() / (float)Mapa::dimension;
    sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
}