#include "Player.hh"
#include "../mapa/EstadoInicial.hh"
#include "../mapa/items/Roca.hh"
#include "../mapa/items/Pared.hh"

Player::Player() {
    int coordX, coordY; // If not found, coords of player are 0,0
    for(int i=0; i<Mapa::dimension; ++i) {
        for(int j=0; j<Mapa::dimension; ++j) {
            if(EstadoInicial::getElementFromCelda(i,j) == 5) {
                coordX = i;
                coordY = j;
            }
        }
    }
    fila = coordX;
    columna = coordY;
    sprite = new SpriteManager(fila, columna, "player");
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}

void Player::evaluate(sf::Event event, Mapa& mapa) {
    if (event.key.code == sf::Keyboard::Left){
        moveLeft(mapa);
    }
    if (event.key.code == sf::Keyboard::Right){
        moveRight(mapa);
    }
    if (event.key.code == sf::Keyboard::Up){
        moveUp(mapa);
    }
    if (event.key.code == sf::Keyboard::Down){
        moveDown(mapa);
    }
}

void Player::updateSpritePosition() {
    sprite->updatePosition(fila, columna);
}

std::string guessDirection(int currFila, int currCol, int objFila, int objCol) {
    if(currFila < objFila) return "down";
    if(currFila > objFila) return "up";
    if(currCol < objCol) return "right";
    if(currCol > objCol) return "left";
    return "";
}

void Player::checkItem(Mapa& mapa, Item* objItem, int desiredFila, int desiredColumna) {
    std::string direction = guessDirection(fila, columna, desiredFila, desiredColumna);
    // Examinar item
    switch(objItem->id) {
        case 1: // Pared
            break;
        case 2: // Roca
            if(dynamic_cast<Roca*>(objItem)->move(mapa, direction) != -1) {    // Returns -1 if it cannot move the rock
                fila = desiredFila;
                columna = desiredColumna;
                updateSpritePosition();
            }
            break;
        case 3: // Agujero
            break;
        case 4: // Agujero relleno
            fila = desiredFila;
            columna = desiredColumna;
            updateSpritePosition();
            break;
        default: break;
    }
}

void Player::moveRight(Mapa& mapa) {
    if(columna == (Mapa::dimension - 1)) return;
    // Check which item is in fila, columna + 1
    Item* objItem = mapa.celdas[{fila, columna + 1}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        columna++;
        updateSpritePosition();
    } else checkItem(mapa, objItem, fila, columna + 1);
}

void Player::moveUp(Mapa& mapa) {
    if(fila == 0) return;
    // Check which item is in fila - 1, columna
    Item* objItem = mapa.celdas[{fila - 1, columna}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        fila--;
        updateSpritePosition();
    } else checkItem(mapa, objItem, fila - 1, columna);
}

void Player::moveDown(Mapa& mapa) {
    if(fila == (Mapa::dimension - 1)) return;
    // Check which item is in fila + 1, columna
    Item* objItem = mapa.celdas[{fila + 1, columna}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        fila++;
        updateSpritePosition();
    } else checkItem(mapa, objItem, fila + 1, columna);
}

void Player::moveLeft(Mapa& mapa) {
    if(columna == 0) return;
    // Check which item is in fila, columna - 1
    Item* objItem = mapa.celdas[{fila, columna - 1}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        columna--;
        updateSpritePosition();
    } else checkItem(mapa, objItem, fila, columna - 1);
}