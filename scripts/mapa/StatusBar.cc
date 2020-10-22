#include "StatusBar.hh"

StatusBar::StatusBar(): background(new SpriteManager("statusBarBackground")), life(new SpriteManager("life")), nolife(new SpriteManager("noLife")), lifeCover(new SpriteManager("lifeCover")) {

}

void StatusBar::draw(sf::RenderWindow& window) const {
    // First draw background
    window.draw(background->getSprite());
    // Draw life sprites
    window.draw(nolife->getSprite());
    window.draw(life->getSprite());
    window.draw(lifeCover->getSprite());
}