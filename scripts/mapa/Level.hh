#pragma once
#include "Mapa.hh"
#include "../entities/Entity.hh"

class Level {
    public:
        Level(int levelId);
        void draw(sf::RenderWindow& window) const;
        Mapa* mapa; // Map of the level
    private:
        int levelId;
        std::vector<Entity*> entities;  // Possible entities in a level
        std::pair<int, int> punteroCeldaObjetivo;   // Celda objetivo para pasar al siguiente nivel
};