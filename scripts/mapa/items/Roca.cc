#include "Roca.hh"
#include "AgujeroRelleno.hh"

Roca::Roca(int fila, int columna): Item(fila, columna, "roca11", 2), spriteState({1,1}) {

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

int Roca::move(Mapa& mapa, std::string direction) {
    int result = -1;
    if(direction == "left") {
        result = moveLeft(mapa);
    }
    if(direction == "right") {
        result = moveRight(mapa);
    }
    if(direction == "up") {
        result = moveUp(mapa);
    }
    if(direction == "down") {
        result = moveDown(mapa);
    }
    // Update texture depending on direction
    if(result != -1) updateTexture(direction);
    return result;  // Cannot move
}

int Roca::checkItem(Mapa& mapa, Item* objItem, int desiredFila, int desiredColumna) {
    // Examinar item
    switch(objItem->id) {
        case 1: // Pared
            return -1;
        case 2: // Roca
            return -1;
        case 3: // Agujero
            mapa.celdas[{desiredFila, desiredColumna}]->pushItem(new AgujeroRelleno(desiredFila, desiredColumna));
            mapa.celdas[{fila, columna}]->removeItem(this);
            return 0;
        case 4: // Agujero relleno
            mapa.celdas[{desiredFila, desiredColumna}]->pushItem(this);
            mapa.celdas[{fila, columna}]->removeItem(this);
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

int Roca::moveLeft(Mapa& mapa) {
    if(columna == 0) return -1;
    // Check wich item is in fila, columna - 1
    Item* objItem = mapa.celdas[{fila, columna - 1}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        mapa.celdas[{fila, columna - 1}]->pushItem(this);
        mapa.celdas[{fila, columna}]->removeItem(this);
        columna--;
        updateSpritePosition();
    } else return checkItem(mapa, objItem, fila, columna - 1);
    return 0;
}

int Roca::moveRight(Mapa& mapa) {
    if(columna == (Mapa::dimension - 1)) return -1;
    // Check wich item is in fila, columna + 1
    Item* objItem = mapa.celdas[{fila, columna + 1}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        mapa.celdas[{fila, columna + 1}]->pushItem(this);
        mapa.celdas[{fila, columna}]->removeItem(this);
        columna++;
        updateSpritePosition();
    } else return checkItem(mapa, objItem, fila, columna + 1);
    return 0;
}

int Roca::moveUp(Mapa& mapa) {
    if(fila == 0) return -1;
    // Check wich item is in fila - 1, columna
    Item* objItem = mapa.celdas[{fila - 1, columna}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        mapa.celdas[{fila - 1, columna}]->pushItem(this);
        mapa.celdas[{fila, columna}]->removeItem(this);
        fila--;
        updateSpritePosition();
    } else return checkItem(mapa, objItem, fila - 1, columna);
    return 0;
}

int Roca::moveDown(Mapa& mapa) {
    if(fila == (Mapa::dimension - 1)) return -1;
    // Check wich item is in fila + 1, columna
    Item* objItem = mapa.celdas[{fila + 1, columna}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        mapa.celdas[{fila + 1, columna}]->pushItem(this);
        mapa.celdas[{fila, columna}]->removeItem(this);
        fila++;
        updateSpritePosition();
    } else return checkItem(mapa, objItem, fila + 1, columna);
    return 0;
}