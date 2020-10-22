#include "StatusBar.hh"

StatusBar::StatusBar(): background(new SpriteManager("statusBarBackground")), life(new SpriteManager("life")) {

}

void StatusBar::draw(sf::RenderWindow& window) const {
    // First draw background
    window.draw(background->getSprite());
    // Draw life sprites
    window.draw(life->getSprite());
}