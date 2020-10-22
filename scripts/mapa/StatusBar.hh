#pragma once
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class StatusBar {
    public:
        StatusBar();
        void draw(sf::RenderWindow& window) const;
        void updateLife(float newLife) {life->updateLife(newLife);}
    private:
        SpriteManager* background;
        SpriteManager* life;
        SpriteManager* nolife;
        SpriteManager* lifeCover;
};