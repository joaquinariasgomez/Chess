#include "SpriteManager.hh"
#include "TextureLoader.hh"

SpriteManager::SpriteManager(int posX, int posY, std::string textureName): posX(posX), posY(posY) {
    texture = TextureLoader::getTexture(textureName);
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(posX, posY));
    sprite.setScale(sf::Vector2f(10.f, 10.f));
}

sf::Sprite SpriteManager::getSprite() const {
    return sprite;
}