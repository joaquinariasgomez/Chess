#include "Player.hh"
#include "../mapa/items/Roca.hh"
#include "../mapa/items/Pared.hh"
#include "../mapa/items/Pincho.hh"
#include "../weapons/Espada.hh"
#include "../weapons/Escudo.hh"

Player::Player(Level* level): currentArma(0), score(0) {
    std::pair<int, int> coords = level->getState()->getPlayerCoords();
    fila = coords.first;
    columna = coords.second;
    sprite = new ItemSprite("player", fila, columna, level->mapa->dimension);

    armas.push_back(NULL);
    armas.push_back(new Espada(fila, columna, level->mapa->dimension));
    armas.push_back(new Escudo(fila, columna, level->mapa->dimension));

    float startingLife = 75;
    statusBar = new StatusBar(startingLife);
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());   // Player sprite
    if(getWeapon() != NULL) {getWeapon()->draw(window);}  // Draw weapon
    statusBar->draw(window);    // StatusBar
}

float Player::getVida() const {return statusBar->getLife()->getVida();}

void Player::hurt(float damage) {
    float vida = this->getVida();
    vida -= damage;
    if(vida < 0) {
        vida = 0;
    }
    statusBar->getLife()->update(vida);
    if(vida == 0) {
        die();
    }
}

void Player::die() {
    std::cout << "YOU DIED" << std::endl;
    std::cout << "Score: " << score << std::endl;
}

Player::EventType Player::evaluateLeft(Level& level) {
    Player::EventType eventType = Player::EventType::NONE;
    if(currentArma == 0) {
        if(moveLeft(level)) {
            eventType = Player::EventType::MOVE;
        }
    }
    if(currentArma == 1) // Espada
    {
        attackLeft(level);
        eventType = Player::EventType::ATTACK_DEFEND;
    }
    if(currentArma == 2) // Escudo
    {
        eventType = Player::EventType::ATTACK_DEFEND;
    }//defendLeft();
    return eventType;
}

Player::EventType Player::evaluateRight(Level& level) {
    Player::EventType eventType = Player::EventType::NONE;
    if(currentArma == 0) {
        if(moveRight(level)) {
            eventType = Player::EventType::MOVE;
        }
    }
    if(currentArma == 1) // Espada
    {
        attackRight(level);
        eventType = Player::EventType::ATTACK_DEFEND;
    }
    if(currentArma == 2) // Escudo
    {
        eventType = Player::EventType::ATTACK_DEFEND;
    }//defendRight();
    return eventType;
}

Player::EventType Player::evaluateUp(Level& level) {
    Player::EventType eventType = Player::EventType::NONE;
    if(currentArma == 0) {
        if(moveUp(level)) {
            eventType = Player::EventType::MOVE;
        }
    }
    if(currentArma == 1) // Espada
    {
        attackUp(level);
        eventType = Player::EventType::ATTACK_DEFEND;
    }
    if(currentArma == 2) // Escudo
    {
        eventType = Player::EventType::ATTACK_DEFEND;
    }//defendUp();
    return eventType;
}

Player::EventType Player::evaluateDown(Level& level) {
    Player::EventType eventType = Player::EventType::NONE;
    if(currentArma == 0) {
        if(moveDown(level)) {
            eventType = Player::EventType::MOVE;
        }
    }
    if(currentArma == 1) // Espada
    {
        attackDown(level);
        eventType = Player::EventType::ATTACK_DEFEND;
    }
    if(currentArma == 2) // Escudo
    {
        eventType = Player::EventType::ATTACK_DEFEND;
    }//defendDown();
    return eventType;
}

void Player::checkCeldaObjetivo(Level& level) const {
    if(std::make_pair(fila, columna) == level.getPunteroCeldaObjetivo()) {
        std::cout << "HE PASADO DE NIVEL" << std::endl;
    }
}

Player::EventType Player::evaluateEvent(sf::Event event, Level& level) {
    Player::EventType eventType = Player::EventType::NONE;
    if (event.key.code == sf::Keyboard::Left){
        eventType = evaluateLeft(level);
    }
    if (event.key.code == sf::Keyboard::Right){
        eventType = evaluateRight(level);
    }
    if (event.key.code == sf::Keyboard::Up){
        eventType = evaluateUp(level);
    }
    if (event.key.code == sf::Keyboard::Down){
        eventType = evaluateDown(level);
    }
    if (event.key.code == sf::Keyboard::A) {
        changeWeapon();
        eventType = Player::EventType::CHANGE_WEAPON;
    }
    checkCeldaObjetivo(level);
    return eventType;
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

bool Player::checkItem(Level& level, Item* objItem, int desiredFila, int desiredColumna) {
    bool canMove = true;
    std::string direction = guessDirection(fila, columna, desiredFila, desiredColumna);
    // Examinar item
    switch(objItem->id) {
        case 1: // Pared
            canMove = false;
            break;
        case 2: // Roca
            if(dynamic_cast<Roca*>(objItem)->move(level, direction) != -1) {    // Returns -1 if it cannot move the rock
                fila = desiredFila;
                columna = desiredColumna;
                updateSpritePosition();
            }
            else {
                canMove = false;
            }
            break;
        case 3: // Agujero
            canMove = false;
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
    return canMove;
}

void Player::attackRight(Level& level) {
    if(level.hasEntity(fila, columna + 1)) {
        bool killedEntity = level.hurtEntity(fila, columna + 1, 30);
        if(killedEntity) {
            dynamic_cast<Espada*>(armas[currentArma])->increaseBloodAmount();
        }
    }
}

void Player::attackLeft(Level& level) {
    if(level.hasEntity(fila, columna - 1)) {
        bool killedEntity = level.hurtEntity(fila, columna - 1, 30);
        if(killedEntity) {
            dynamic_cast<Espada*>(armas[currentArma])->increaseBloodAmount();
        }
    }
}

void Player::attackUp(Level& level) {
    if(level.hasEntity(fila - 1, columna)) {
        bool killedEntity = level.hurtEntity(fila - 1, columna, 30);
        if(killedEntity) {
            dynamic_cast<Espada*>(armas[currentArma])->increaseBloodAmount();
        }
    }
}

void Player::attackDown(Level& level) {
    if(level.hasEntity(fila + 1, columna)) {
        bool killedEntity = level.hurtEntity(fila + 1, columna, 30);
        if(killedEntity) {
            dynamic_cast<Espada*>(armas[currentArma])->increaseBloodAmount();
        }
    }
}

bool Player::moveRight(Level& level) {
    if(columna == (level.mapa->dimension - 1)) return false;
    // Check if level has entities in desiredPosition
    if(level.hasEntity(fila, columna + 1)) return false;
    bool canMove = true;
    // Check which item is in fila, columna + 1
    Item* objItem = level.mapa->celdas[{fila, columna + 1}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        columna++;
        updateSpritePosition();
    } else {
        canMove = checkItem(level, objItem, fila, columna + 1);
    }
    return canMove;
}

bool Player::moveUp(Level& level) {
    if(fila == 0) return false;
    // Check if level has entities in desiredPosition
    if(level.hasEntity(fila - 1, columna)) return false;
    bool canMove = true;
    // Check which item is in fila - 1, columna
    Item* objItem = level.mapa->celdas[{fila - 1, columna}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        fila--;
        updateSpritePosition();
    } else {
        canMove = checkItem(level, objItem, fila - 1, columna);
    }
    return canMove;
}

bool Player::moveDown(Level& level) {
    if(fila == (level.mapa->dimension - 1)) return false;
    // Check if level has entities in desiredPosition
    if(level.hasEntity(fila + 1, columna)) return false;
    bool canMove = true;
    // Check which item is in fila + 1, columna
    Item* objItem = level.mapa->celdas[{fila + 1, columna}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        fila++;
        updateSpritePosition();
    } else {
        canMove = checkItem(level, objItem, fila + 1, columna);
    }
    return canMove;
}

bool Player::moveLeft(Level& level) {
    if(columna == 0) return false;
    // Check if level has entities in desiredPosition
    if(level.hasEntity(fila, columna - 1)) return false;
    bool canMove = true;
    // Check which item is in fila, columna - 1
    Item* objItem = level.mapa->celdas[{fila, columna - 1}]->getLastItem();
    if(objItem == NULL) {
        // Mover con normalidad
        columna--;
        updateSpritePosition();
    } else {
        canMove = checkItem(level, objItem, fila, columna - 1);
    }
    return canMove;
}
