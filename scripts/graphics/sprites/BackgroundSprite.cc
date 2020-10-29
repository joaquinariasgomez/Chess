#include "BackgroundSprite.hh"
#include "../TextureLoader.hh"
#include "../Window.hh"

BackgroundSprite::BackgroundSprite(std::string textureName): SpriteManager(textureName) {
    texture = TextureLoader::getTexture(textureName);
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    //Sprite properties
    sprite.setPosition(sf::Vector2f(0, Window::getBarHeight()));
    sprite.setScale(sf::Vector2f((float)Window::getMapWidth()/(float)textureWidth, (float)Window::getMapHeight()/(float)textureHeight));
}