#include "Player.hh"
#include "../mapa/EstadoInicial.hh"
#include "../mapa/items/Roca.hh"
#include "../mapa/items/Pared.hh"
#include "../mapa/items/Pincho.hh"
#include "../weapons/Espada.hh"
#include "../weapons/Escudo.hh"

Player::Player(StatusBar* statusBar): vida(75), statusBar(statusBar), currentArma(0) {
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
    statusBar->updateLife(vida);

    armas.push_back(NULL);
    armas.push_back(new Espada(fila, columna));
    armas.push_back(new Escudo(fila, columna));
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());   // Player sprite
    if(getWeapon() != NULL) {getWeapon()->draw(window);}  // Draw weapon
}

void Player::hurt(int damage) {
    vida -= damage;
    if(vida < 0) {
        vida = 0;
    }
    statusBar->updateLife(vida);
    if(vida == 0) {
        // Player dies
    }
}

void Player::evaluateLeft(Mapa& mapa) {
    if(currentArma == 0) moveLeft(mapa);
    if(currentArma == 1) // Espada
        {}//attackLeft();
    if(currentArma == 2) // Escudo
        {}//defendLeft();
}

void Player::evaluateRight(Mapa& mapa) {
    if(currentArma == 0) moveRight(mapa);
    if(currentArma == 1) // Espada
        {}//attackRight();
    if(currentArma == 2) // Escudo
        {}//defendRight();
}

void Player::evaluateUp(Mapa& mapa) {
    if(currentArma == 0) moveUp(mapa);
    if(currentArma == 1) // Espada
        {}//attackUp();
    if(currentArma == 2) // Escudo
        {}//defendUp();
}

void Player::evaluateDown(Mapa& mapa) {
    if(currentArma == 0) moveDown(mapa);
    if(currentArma == 1) // Espada
        {}//attackDown();
    if(currentArma == 2) // Escudo
        {}//defendDown();
}

void Player::evaluateEvent(sf::Event event, Mapa& mapa) {
    if (event.key.code == sf::Keyboard::Left){
        evaluateLeft(mapa);
    }
    if (event.key.code == sf::Keyboard::Right){
        evaluateRight(mapa);
    }
    if (event.key.code == sf::Keyboard::Up){
        evaluateUp(mapa);
    }
    if (event.key.code == sf::Keyboard::Down){
        evaluateDown(mapa);
    }
    if (event.key.code == sf::Keyboard::A) {
        changeWeapon();
    }
}

void Player::changeWeapon() {
    (currentArma == 2) ? currentArma = 0 : ++currentArma;
}

Arma* Player::getWeapon() const {
    return armas[currentArma];
}

void Player::updateSpritePosition() {
    sprite->updatePosition(fila, columna);
    for(auto arma: armas) {
        if(arma != NULL) arma->updatePosition(fila, columna);
    }
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
        case 6: // Pincho1
            fila = desiredFila;
            columna = desiredColumna;
            updateSpritePosition();
            dynamic_cast<Pincho*>(objItem)->hurt(*this);
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