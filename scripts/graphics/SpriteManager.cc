#include "SpriteManager.hh"
#include "TextureLoader.hh"
#include "../mapa/Mapa.hh"
#include "../entities/Player.hh"
#include "Window.hh"

SpriteManager::SpriteManager(int fila, int columna, std::string textureName) {
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
        float spriteWidth = (float)Window::getMapWidth() / (float)Mapa::dimension;
        float spriteHeight = (float)Window::getMapHeight() / (float)Mapa::dimension;
        sprite.setPosition(sf::Vector2f(columna * spriteHeight, fila * spriteWidth + Window::getBarHeight()));
        sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
    }
}

SpriteManager::SpriteManager(std::string textureName) { // StatusBar
    if(textureName == "statusBarBackground") {
        texture = TextureLoader::getTexture(textureName);
        sprite.setTexture(texture);

        sf::Vector2u texSize = texture.getSize();
        unsigned int textureWidth = texSize.x;
        unsigned int textureHeight = texSize.y;
        sprite.setPosition(sf::Vector2f(0, 0));
        sprite.setScale(sf::Vector2f((float)Window::getBarWidth()/(float)textureWidth, (float)Window::getBarHeight()/(float)textureHeight));
    }
    else {  // Life
        renderLife(textureName, Player::maxVida);
    }
}

void SpriteManager::renderLife(std::string textureName, float currVida) { // StatusBar
    float maxVida = Player::maxVida;

    texture = TextureLoader::getTexture(textureName);
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    sprite.setPosition(sf::Vector2f(Window::getBarLifeSeparationWidth(), Window::getBarLifeSeparationHeight()));
    float lifeMaxWidthPix = Window::getBarWidth() - Window::getBarLifeSeparationWidth();
    float currLifeWidthPix = (currVida / maxVida) * lifeMaxWidthPix;
    sprite.setScale(sf::Vector2f(currLifeWidthPix/(float)textureWidth, (float)Window::getBarLifeHeight()/(float)textureHeight));
}

void SpriteManager::updateLife(float life) { // StatusBar
    renderLife("life", life);
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