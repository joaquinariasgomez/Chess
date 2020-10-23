#include "Escudo.hh"

Escudo::Escudo(int fila, int columna): Arma(fila, columna, "escudo", 2) {

}

void Escudo::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}