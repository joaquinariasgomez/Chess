#pragma once
#include "../graphics/SpriteManager.hh"
#include "Vida.hh"
#include <SFML/Graphics.hpp>

class StatusBar {
    public:
        StatusBar(float startingLife);
        void draw(sf::RenderWindow& window) const;
        Vida* getLife() const {return vida;}
    private:
        Vida* vida;
        SpriteManager* background;
        SpriteManager* nolife;
        SpriteManager* lifeCover;
};