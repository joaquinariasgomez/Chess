#include "Pared.hh"

Pared::Pared(int fila, int columna): Item(fila, columna, "pared") {

}

void Pared::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}