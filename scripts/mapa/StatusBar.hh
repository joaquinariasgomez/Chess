#pragma once
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class StatusBar {
    public:
        StatusBar();
        void draw(sf::RenderWindow& window) const;
    private:
        SpriteManager* sprite;
};