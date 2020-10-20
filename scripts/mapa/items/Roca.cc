#include "Roca.hh"

Roca::Roca(int fila, int columna): Item(fila, columna, "roca") {

}

void Roca::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}