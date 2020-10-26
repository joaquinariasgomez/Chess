#pragma once
#include "Celda.hh"
#include "ReadState.hh"
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>
#include <map>
#include <utility>

class Mapa {
    public:
        Mapa(int levelId, ReadState* state, std::pair<int, int> punteroCeldaObjetivo);
        void draw(sf::RenderWindow& window) const;

        std::map<std::pair<int, int>, Celda*> celdas;
        int dimension;
    private:   
        SpriteManager* sprite;  //background sprite
};