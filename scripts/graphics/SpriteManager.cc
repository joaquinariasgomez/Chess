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
        sprite.setPosition(sf::Vector2f(0, 0));
        sprite.setScale(sf::Vector2f((float)Window::getWindowWidth()/(float)textureWidth, (float)Window::getWindowHeight()/(float)textureHeight));
    }
    else {
        float spriteWidth = (float)Window::getWindowWidth() / (float)Mapa::dimension;
        float spriteHeight = (float)Window::getWindowHeight() / (float)Mapa::dimension;
        sprite.setPosition(sf::Vector2f(columna * spriteHeight, fila * spriteWidth));
        sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
    }
}

void SpriteManager::updatePosition(int fila, int columna) {
    float spriteWidth = (float)Window::getWindowWidth() / (float)Mapa::dimension;
    float spriteHeight = (float)Window::getWindowHeight() / (float)Mapa::dimension;
    sprite.setPosition(sf::Vector2f(columna * spriteHeight, fila * spriteWidth));
}

sf::Sprite SpriteManager::getSprite() const {
    return sprite;
}