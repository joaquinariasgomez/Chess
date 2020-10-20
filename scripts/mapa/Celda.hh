#pragma once
#include <iostream>
#include "FichaO.hh"
#include "FichaX.hh"
#include "../graphics/SpriteManager.hh"
#include <SFML/Graphics.hpp>

class Celda {
    public:
        Celda(int fila, int columna, int fichaValor);
        void draw(sf::RenderWindow& window) const;
        const Ficha* getFicha() const {return ficha;}
    private:
        int fila_;
        int columna_;
        Ficha* ficha;
        SpriteManager* sprite;
};