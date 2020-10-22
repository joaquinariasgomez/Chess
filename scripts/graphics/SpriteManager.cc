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
        if(textureName == "life") {
            renderLife(Player::maxVida);
        }
        else {
            if(textureName == "noLife") {
                renderNoLife();
            }
            else {
                renderLifeCover();
            }
        }
    }
}

void SpriteManager::renderLife(float currVida) { // StatusBar
    float maxVida = Player::maxVida;

    texture = TextureLoader::getTexture("life");
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    sprite.setPosition(sf::Vector2f(Window::getBarLifeSeparationWidth(), Window::getBarLifeSeparationHeight()));
    float lifeMaxWidthPix = Window::getBarWidth() - Window::getBarLifeSeparationWidth() - Window::getPixelSize()*2;
    float currLifeWidthPix = (currVida / maxVida) * lifeMaxWidthPix;
    sprite.setScale(sf::Vector2f(currLifeWidthPix/(float)textureWidth, (float)Window::getBarLifeHeight()/(float)textureHeight));
}

void SpriteManager::renderNoLife() {
    texture = TextureLoader::getTexture("noLife");
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    sprite.setPosition(sf::Vector2f(Window::getBarLifeSeparationWidth(), Window::getBarLifeSeparationHeight()));
    float lifeMaxWidthPix = Window::getBarWidth() - Window::getBarLifeSeparationWidth() - Window::getPixelSize()*2;
    sprite.setScale(sf::Vector2f(lifeMaxWidthPix/(float)textureWidth, (float)Window::getBarLifeHeight()/(float)textureHeight));
}

void SpriteManager::renderLifeCover() { // StatusBar
    texture = TextureLoader::getTexture("lifeCover");
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    float lifeMaxWidthPix = Window::getBarWidth() - Window::getBarLifeSeparationWidth() + Window::getPixelSize()*2;
    float lifeMaxHeightPix = (float)Window::getBarLifeHeight() + Window::getPixelSize()*4;

    sprite.setPosition(sf::Vector2f(Window::getBarLifeSeparationWidth() - Window::getPixelSize()*2, Window::getBarLifeSeparationHeight() - Window::getPixelSize()*2));
    sprite.setScale(sf::Vector2f(lifeMaxWidthPix/(float)textureWidth,lifeMaxHeightPix/(float)textureHeight));
}

void SpriteManager::updateLife(float life) { // StatusBar
    renderLife(life);
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