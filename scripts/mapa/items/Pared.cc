#include "Pared.hh"

Pared::Pared(int fila, int columna, int mapDimension): Item(fila, columna, mapDimension, "pared", 1) {

}

void Pared::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}