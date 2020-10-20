#include "Celda.hh"

Celda::Celda(int fila, int columna, int fichaValor): fila_(fila), columna_(columna), sprite(new SpriteManager(fila, columna, "celda")) {
    switch(fichaValor) {
        case 1: ficha = new FichaO(); break;
        case 2: ficha = new FichaX(); break;
        case -1:
        default: ficha = NULL;
    }
}

void Celda::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}