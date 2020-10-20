#include "Roca.hh"

Roca::Roca(int fila, int columna): Item(fila, columna, "roca", 2) {

}

void Roca::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}

int Roca::move(std::string direction) {
    if(direction == "left") {
        return moveLeft();
    }
    if(direction == "right") {
        return moveRight();
    }
    if(direction == "up") {
        return moveUp();
    }
    if(direction == "down") {
        return moveDown();
    }
    return -1;  // Cannot move
}

int Roca::moveLeft() {
    return -1;
}

int Roca::moveRight() {
    
}

int Roca::moveUp() {
    return -1;
}

int Roca::moveDown() {
    return -1;
}