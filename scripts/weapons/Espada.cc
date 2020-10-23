#include "Espada.hh"

Espada::Espada(int fila, int columna): Arma(fila, columna, "sword", 1), bloodAmount(0) {

}

void Espada::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}

void Espada::updatePosition(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    getSprite()->updatePosition(fila, columna);
}