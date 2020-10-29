#include "StatusBar.hh"

StatusBar::StatusBar(float startingLife): vida(new Vida(startingLife)), background(new StatusBarSprite("statusBarBackground", "background")), nolife(new StatusBarSprite("noLife", "noLife")), lifeCover(new StatusBarSprite("lifeCover", "lifeCover")) {}

void StatusBar::draw(sf::RenderWindow& window) const {
    // First draw background
    window.draw(background->getSprite());
    // Draw life sprites
    window.draw(nolife->getSprite());
    vida->draw(window);
    window.draw(lifeCover->getSprite());
}
