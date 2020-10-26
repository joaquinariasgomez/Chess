#pragma once
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class Vida {
    public:
        Vida(float value);
        void draw(sf::RenderWindow& window) const;
        void update(float nuevaVida) {vida = nuevaVida; life->updateLife(nuevaVida);}
        float getVida() const {return vida;}
    private:
        float vida;
        //TODO: More things related to regeneration and poison
        SpriteManager* life;
};