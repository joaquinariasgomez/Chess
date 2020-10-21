#include "StatusBar.hh"

StatusBar::StatusBar(): sprite(new SpriteManager(fila, columna, "statusBar")) {

}

void StatusBar::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}