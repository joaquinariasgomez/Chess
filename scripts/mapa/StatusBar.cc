#include "StatusBar.hh"

StatusBar::StatusBar(float startingLife): vida(new Vida(startingLife)), background(new SpriteManager("statusBarBackground")), nolife(new SpriteManager("noLife")), lifeCover(new SpriteManager("lifeCover")) {

}

void StatusBar::draw(sf::RenderWindow& window) const {
    // First draw background
    window.draw(background->getSprite());
    // Draw life sprites
    window.draw(nolife->getSprite());
    vida->draw(window);
    window.draw(lifeCover->getSprite());
}