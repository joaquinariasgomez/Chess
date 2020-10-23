#include "Espada.hh"

Espada::Espada(int fila, int columna): Arma(fila, columna, "espada", 1) {

}

void Espada::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}