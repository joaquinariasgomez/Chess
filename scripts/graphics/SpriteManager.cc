#include "SpriteManager.hh"
#include "TextureLoader.hh"
#include "Window.hh"

SpriteManager::SpriteManager(int posX, int posY, int dimension, std::string textureName): posX(posX), posY(posY) {
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
        float spriteWidth = (float)Window::getWindowWidth() / (float)dimension;
        float spriteHeight = (float)Window::getWindowHeight() / (float)dimension;
        sprite.setPosition(sf::Vector2f(posX * spriteWidth, posY * spriteHeight));
        sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
    }

    //sprite.setScale(sf::Vector2f(10.f, 10.f));
}

sf::Sprite SpriteManager::getSprite() const {
    return sprite;
}