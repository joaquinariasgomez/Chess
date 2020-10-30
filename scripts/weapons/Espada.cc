#include "Espada.hh"

Espada::Espada(int fila, int columna, int mapDimension): Arma(fila, columna, mapDimension, "sword", 1), bloodAmount(0) {

}

void Espada::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}

void Espada::updatePosition(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
    getSprite()->updatePosition(fila, columna);
}

void Espada::increaseBloodAmount() {
    if(bloodAmount < 4)  {
        ++bloodAmount;
    }
    switch(bloodAmount) {
        default:
        case 0: sprite->updateTexture("sword"); break;
        case 1: sprite->updateTexture("swordBlood1"); break;
        case 2: sprite->updateTexture("swordBlood2"); break;
        case 3: sprite->updateTexture("swordBlood3"); break;
        case 4: sprite->updateTexture("swordBlood4"); break;
    }
}