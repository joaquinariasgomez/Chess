#include "SpriteManager.hh"
#include "TextureLoader.hh"
#include "../mapa/Mapa.hh"
#include "Window.hh"

SpriteManager::SpriteManager(int posX, int posY, std::string textureName): posX(posX), posY(posY) {
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
        sprite.setPosition(sf::Vector2f(posY * spriteHeight, posX * spriteWidth));
        sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
    }
}

sf::Sprite SpriteManager::getSprite() const {
    return sprite;
}