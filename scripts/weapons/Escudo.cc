#include "Escudo.hh"

Escudo::Escudo(int fila, int columna): Arma(fila, columna, "escudo", 2) {

}

void Escudo::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}

void Escudo::updatePosition(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    getSprite()->updatePosition(fila, columna);
}