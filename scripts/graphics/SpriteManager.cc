#include "SpriteManager.hh"
#include "TextureLoader.hh"
#include "../mapa/Mapa.hh"
#include "../entities/Player.hh"
#include "Window.hh"

SpriteManager::SpriteManager(int fila, int columna, std::string textureName, bool weapon) {
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
        if(weapon) {
            renderWeapon(fila, columna);
        }
        else {
            float spriteWidth = (float)Window::getMapWidth() / (float)Mapa::dimension;
            float spriteHeight = (float)Window::getMapHeight() / (float)Mapa::dimension;
            sprite.setPosition(sf::Vector2f(columna * spriteHeight, fila * spriteWidth + Window::getBarHeight()));
            sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
        }
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
            renderLife(Vida::maxVida);
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

void SpriteManager::renderWeapon(int fila, int columna) {
    sf::Vector2u texSize = texture.getSize();

    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    float spriteWidth = (float)Window::getMapWidth() / (float)Mapa::dimension;
    float spriteHeight = (float)Window::getMapHeight() / (float)Mapa::dimension;
    sprite.setPosition(sf::Vector2f(columna * spriteHeight, fila * spriteWidth + Window::getBarHeight()));
    sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
}

void SpriteManager::renderLife(float currVida) { // StatusBar
    float maxVida = Vida::maxVida;

    texture = TextureLoader::getTexture("life");
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    float relationCoverAndTexture = (float)(Window::getBarWidth() - Window::getBarLifeSeparationWidth()) / (float)(textureWidth * 10);
    float lifeWidthScale = (float)(Window::getBarWidth() - Window::getBarLifeSeparationWidth() - 4*relationCoverAndTexture) / (float)(textureWidth * 10);
    const float relationBetweenLifeAndStamina = 0.63;
    float lifeHeightScale = (float)(Window::getBarHeight() - 4*relationCoverAndTexture)*relationBetweenLifeAndStamina / (float)textureHeight;

    sprite.setPosition(sf::Vector2f(Window::getBarLifeSeparationWidth() + 2*relationCoverAndTexture, Window::getBarLifeSeparationHeight() + 2*relationCoverAndTexture));
    sprite.setScale(sf::Vector2f(lifeWidthScale * (currVida * 10 / maxVida), lifeHeightScale));
}

void SpriteManager::renderNoLife() {
    texture = TextureLoader::getTexture("noLife");
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    float relationCoverAndTexture = (float)(Window::getBarWidth() - Window::getBarLifeSeparationWidth()) / (float)(textureWidth * 10);
    float noLifeWidthScale = (float)(Window::getBarWidth() - Window::getBarLifeSeparationWidth() - 4*relationCoverAndTexture) / (float)(textureWidth * 10);
    const float relationBetweenLifeAndStamina = 0.63;
    float noLifeHeightScale = (float)(Window::getBarHeight() - 4*relationCoverAndTexture)*relationBetweenLifeAndStamina / (float)textureHeight;

    sprite.setPosition(sf::Vector2f(Window::getBarLifeSeparationWidth() + 2*relationCoverAndTexture, Window::getBarLifeSeparationHeight() + 2*relationCoverAndTexture));
    sprite.setScale(sf::Vector2f(noLifeWidthScale * 10, noLifeHeightScale));
}

void SpriteManager::renderLifeCover() { // StatusBar
    texture = TextureLoader::getTexture("lifeCover");
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    float lifeCoverWidthScale = (float)(Window::getBarWidth() - Window::getBarLifeSeparationWidth()) / (float)textureWidth;
    float lifeCoverHeightScale = (float)(Window::getBarHeight()) / (float)textureHeight;

    sprite.setPosition(sf::Vector2f(Window::getBarLifeSeparationWidth(), Window::getBarLifeSeparationHeight()));
    sprite.setScale(sf::Vector2f(lifeCoverWidthScale,lifeCoverHeightScale));
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