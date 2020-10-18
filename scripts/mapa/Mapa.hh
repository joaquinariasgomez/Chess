#pragma once
#include "Celda.hh"
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>
#include <map>
#include <utility>

class Mapa {
    public:
        Mapa(int dimension);
        const int getDimension() const {return dimension_;}
        const Celda* getCelda(int x, int y) {return celdas[{x,y}];}
        void draw(sf::RenderWindow& window) const {window.draw(sprite->getSprite());}

        std::map<std::pair<int, int>, const Celda*> celdas;
    private:
        int dimension_;
        SpriteManager* sprite;  //background sprite
};