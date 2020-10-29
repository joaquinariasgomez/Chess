#include "StatusBarSprite.hh"
#include "../../mapa/Vida.hh"
#include "../TextureLoader.hh"
#include "../Window.hh"

StatusBarSprite::StatusBarSprite(std::string textureName, std::string textureType): SpriteManager(textureName) {
    if(textureType == "background") {
        renderBackground();
    }
    if(textureType == "life") {
        renderLife(Vida::maxVida);
    }
    if(textureType == "noLife") {
        renderNoLife();
    }
    if(textureType == "lifeCover") {
        renderLifeCover();
    }
}

void StatusBarSprite::renderBackground() {
    texture = TextureLoader::getTexture(textureName);
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;
    sprite.setPosition(sf::Vector2f(0, 0));
    sprite.setScale(sf::Vector2f((float)Window::getBarWidth()/(float)textureWidth, (float)Window::getBarHeight()/(float)textureHeight));
}

void StatusBarSprite::renderLife(float currVida) {
    float maxVida = Vida::maxVida;

    texture = TextureLoader::getTexture(textureName);
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

void StatusBarSprite::renderNoLife() {
    texture = TextureLoader::getTexture(textureName);
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

void StatusBarSprite::renderLifeCover() {
    texture = TextureLoader::getTexture(textureName);
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    float lifeCoverWidthScale = (float)(Window::getBarWidth() - Window::getBarLifeSeparationWidth()) / (float)textureWidth;
    float lifeCoverHeightScale = (float)(Window::getBarHeight()) / (float)textureHeight;

    sprite.setPosition(sf::Vector2f(Window::getBarLifeSeparationWidth(), Window::getBarLifeSeparationHeight()));
    sprite.setScale(sf::Vector2f(lifeCoverWidthScale,lifeCoverHeightScale));
}

void StatusBarSprite::updateLife(float life) {
    renderLife(life);
}