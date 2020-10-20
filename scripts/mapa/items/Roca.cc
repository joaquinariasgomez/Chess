#include "Roca.hh"

Roca::Roca(int fila, int columna): Item(fila, columna, "roca", 2), fila(fila), columna(columna) {

}

void Roca::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}

int Roca::move(Mapa& mapa, std::string direction) {
    if(direction == "left") {
        return moveLeft(mapa);
    }
    if(direction == "right") {
        return moveRight(mapa);
    }
    if(direction == "up") {
        return moveUp(mapa);
    }
    if(direction == "down") {
        return moveDown(mapa);
    }
    return -1;  // Cannot move
}

void Roca::updateSpritePosition() {
    sprite->updatePosition(fila, columna);
}

int Roca::moveLeft(Mapa& mapa) {
    return -1;
}

int Roca::moveRight(Mapa& mapa) {
    // Mover con normalidad
    mapa.celdas[{fila, columna+1}]->setItem(this);
    mapa.celdas[{fila, columna}]->setItem(NULL);
    //columna++;
    //updateSpritePosition();
    return 0;
}

int Roca::moveUp(Mapa& mapa) {
    return -1;
}

int Roca::moveDown(Mapa& mapa) {
    return -1;
}