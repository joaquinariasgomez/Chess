#pragma once
#include "Celda.hh"
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>
#include <map>
#include <utility>

class Mapa {
    public:
        Mapa();
        const Celda* getCelda(int x, int y) {return celdas[{x,y}];}
        void draw(sf::RenderWindow& window) const;

        std::map<std::pair<int, int>, Celda*> celdas;
        static int dimension;
    private:   
        SpriteManager* sprite;  //background sprite
};