#pragma once
#include "Mapa.hh"
#include "../entities/Entity.hh"
#include "ReadState.hh"

class Level {
    public:
        Level(int levelId);
        void draw(sf::RenderWindow& window) const;
        const ReadState* getState() const {return state;}
        std::pair<int, int> getPunteroCeldaObjetivo() const {return punteroCeldaObjetivo;}
        Mapa* mapa; // Map of the level
    private:
        int levelId;
        std::vector<Entity*> entities;  // Possible entities in a level
        std::pair<int, int> punteroCeldaObjetivo;   // Celda objetivo para pasar al siguiente nivel
        ReadState* state;
        //
        void initiateSkeletons(std::vector<std::pair<int, int>> skeletonCoords);
};