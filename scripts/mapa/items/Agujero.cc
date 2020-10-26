#include "Agujero.hh"

Agujero::Agujero(int fila, int columna, int mapDimension): Item(fila, columna, mapDimension, "agujero", 3) {

}

void Agujero::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}