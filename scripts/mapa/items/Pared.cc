#include "Pared.hh"

Pared::Pared(int fila, int columna): Item(fila, columna, "pared", 1) {

}

void Pared::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}