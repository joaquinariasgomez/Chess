#include "Agujero.hh"

Agujero::Agujero(int fila, int columna): Item(fila, columna, "test", 3) {

}

void Agujero::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}