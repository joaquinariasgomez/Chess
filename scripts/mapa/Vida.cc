#include "Vida.hh"

Vida::Vida(float value): vida(value), life(new StatusBarSprite("life", "life")) {
    life->updateLife(value);
}

void Vida::draw(sf::RenderWindow& window) const {
    window.draw(life->getSprite());
}
