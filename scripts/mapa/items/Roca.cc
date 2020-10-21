#include "Roca.hh"
#include "AgujeroRelleno.hh"

Roca::Roca(int fila, int columna): Item(fila, columna, "roca11", 2), spriteState({1,1}) {

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