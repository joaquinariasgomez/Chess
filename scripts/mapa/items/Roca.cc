#include "Roca.hh"
#include "AgujeroRelleno.hh"

Roca::Roca(int fila, int columna, int mapDimension): Item(fila, columna, mapDimension, "roca11", 2), spriteState({1,1}) {

}

void Roca::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}

void Roca::updateTexture(std::string direction) {
    if(direction == "right") {
        (spriteState.second < 2) ? spriteState.second++ : spriteState.second = 0;
        if(spriteState.first != 1) spriteState.first = 1;
    }
    if(direction == "left") {
        (spriteState.second > 0) ? spriteState.second-- : spriteState.second = 2;
        if(spriteState.first != 1) spriteState.first = 1;
    }
    if(direction == "up") {
        (spriteState.first > 0) ? spriteState.first-- : spriteState.first = 2;
        if(spriteState.second != 1) spriteState.second = 1;
    }
    if(direction == "down") {
        (spriteState.first < 2) ? spriteState.first++ : spriteState.first = 0;
        if(spriteState.second != 1) spriteState.second = 1;
    }
    sprite->updateTexture("roca"+std::to_string(spriteState.first)+std::to_string(spriteState.second));
}

int Roca::move(Level& level, std::string direction) {
    int result = -1;
    if(direction == "left") {
        result = moveLeft(level);
    }
    if(direction == "right") {
        result = moveRight(level);
    }
    if(direction == "up") {
        result = moveUp(level);
    }
    if(direction == "down") {
        result = moveDown(level);
    }
    // Update texture depending on direction
    if(result != -1) updateTexture(direction);
    return result;  // Cannot move
}

int Roca::checkItem(Level& level, Item* objItem, int desiredFila, int desiredColumna) {
    // Examinar item
    switch(objItem->id) {
        case 1: // Pared
            return -1;
        case 2: // Roca
            return -1;
        case 3: // Agujero
            level.mapa->celdas[{desiredFila, desiredColumna}]->pushItem(new AgujeroRelleno(desiredFila, desiredColumna, mapDimension));
            level.mapa->celdas[{fila, columna}]->removeItem(this);
            return 0;
        case 4: // Agujero relleno
            level.mapa->celdas[{desiredFila, desiredColumna}]->pushItem(this);
            level.mapa->celdas[{fila, columna}]->removeItem(this);
            fila = desiredFila;
            columna = desiredColumna;
            updateSpritePosition();
            return 0;
        default: return -1;
    }
    return -1;
}

void Roca::updateSpritePosition() {
    sprite->updatePosition(fila, columna);
}

int Roca::moveLeft(Level& level) {
    if(columna == 0) return -1;
    // Check if level has entities in desiredPosition
    if(level.hasEntity(fila, columna - 1)) return -1;
    // Check wich item is in fila, columna - 1
    Item* objItem = level.mapa->celdas[{fila, columna - 1}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        level.mapa->celdas[{fila, columna - 1}]->pushItem(this);
        level.mapa->celdas[{fila, columna}]->removeItem(this);
        columna--;
        updateSpritePosition();
    } else return checkItem(level, objItem, fila, columna - 1);
    return 0;
}

int Roca::moveRight(Level& level) {
    if(columna == (level.mapa->dimension - 1)) return -1;
    // Check if level has entities in desiredPosition
    if(level.hasEntity(fila, columna + 1)) return -1;
    // Check wich item is in fila, columna + 1
    Item* objItem = level.mapa->celdas[{fila, columna + 1}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        level.mapa->celdas[{fila, columna + 1}]->pushItem(this);
        level.mapa->celdas[{fila, columna}]->removeItem(this);
        columna++;
        updateSpritePosition();
    } else return checkItem(level, objItem, fila, columna + 1);
    return 0;
}

int Roca::moveUp(Level& level) {
    if(fila == 0) return -1;
    // Check if level has entities in desiredPosition
    if(level.hasEntity(fila - 1, columna)) return -1;
    // Check wich item is in fila - 1, columna
    Item* objItem = level.mapa->celdas[{fila - 1, columna}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        level.mapa->celdas[{fila - 1, columna}]->pushItem(this);
        level.mapa->celdas[{fila, columna}]->removeItem(this);
        fila--;
        updateSpritePosition();
    } else return checkItem(level, objItem, fila - 1, columna);
    return 0;
}

int Roca::moveDown(Level& level) {
    if(fila == (level.mapa->dimension - 1)) return -1;
    // Check if level has entities in desiredPosition
    if(level.hasEntity(fila + 1, columna)) return -1;
    // Check wich item is in fila + 1, columna
    Item* objItem = level.mapa->celdas[{fila + 1, columna}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        level.mapa->celdas[{fila + 1, columna}]->pushItem(this);
        level.mapa->celdas[{fila, columna}]->removeItem(this);
        fila++;
        updateSpritePosition();
    } else return checkItem(level, objItem, fila + 1, columna);
    return 0;
}