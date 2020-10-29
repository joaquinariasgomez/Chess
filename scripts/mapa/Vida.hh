#pragma once
#include "../graphics/sprites/StatusBarSprite.hh"
#include <SFML/Graphics.hpp>

class Vida {
    public:
        Vida(float value);
        void draw(sf::RenderWindow& window) const;
        void update(float nuevaVida) {vida = nuevaVida; life->updateLife(nuevaVida);}
        float getVida() const {return vida;}
        static float maxVida;
    private:
        float vida;
        //TODO: More things related to regeneration and poison
        StatusBarSprite* life;
};
