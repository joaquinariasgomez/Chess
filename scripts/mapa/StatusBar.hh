#pragma once
#include "../graphics/sprites/StatusBarSprite.hh"
#include "Vida.hh"
#include <SFML/Graphics.hpp>

class StatusBar {
    public:
        StatusBar(float startingLife);
        void draw(sf::RenderWindow& window) const;
        Vida* getLife() const {return vida;}
    private:
        Vida* vida;
        StatusBarSprite* background;
        StatusBarSprite* nolife;
        StatusBarSprite* lifeCover;
};
