#include "Vida.hh"

Vida::Vida(float value): vida(value), life(new SpriteManager("life")) {
    life->updateLife(value);
}

void Vida::draw(sf::RenderWindow& window) const {
    window.draw(life->getSprite());
}