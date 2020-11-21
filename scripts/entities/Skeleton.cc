#include "Skeleton.hh"
#include "Player.hh"
#include <iostream>

Skeleton::Skeleton(float vida, int fila, int columna, int mapDimension): Entity(vida, "skeleton", fila, columna, mapDimension), isGoingToAttackSprite(new ItemSprite("test", fila, columna, mapDimension)), isGoingToAttack(false), isAttacking(false), attackDirection(AttackDirection::NONE), currentTimeWithoutAttacking(0) {
}

void Skeleton::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
    if(isGoingToAttack) {
        window.draw(isGoingToAttackSprite->getSprite());
    }
}

void Skeleton::hurt(float damage) {
    vida -= damage;
    if(vida < 0) {
        vida = 0;
    }
    // TODO: Update texture according to vida
    //
}

bool Skeleton::isDead() const {
    return vida == 0;
}

void Skeleton::update(Player& player, Mapa& mapa) {
    attackIfPlayerIsClose(player, mapa);
}

void Skeleton::attackIfPlayerIsClose(Player& player, Mapa& mapa) {
    isAttacking = false;
    if(isGoingToAttack) {
        performAttack(mapa, player);
    }
    else {
        //Esperar attackSpeed
        if(!isAttacking) {
            if(currentTimeWithoutAttacking < ATTACK_SPEED) {
                ++currentTimeWithoutAttacking;
                if(playerIsClose(player)) {
                    isGoingToAttack = true;
                    attackDirection = guessAttackDirection(player);
                }
            }
            else {
                currentTimeWithoutAttacking = 0;
            }
        }
    }
    if(!isAttacking) {
        resetTextureFromCeldas(mapa);
    }
}

void Skeleton::performAttack(Mapa& mapa, Player& player) {
    updateTextureFromCeldas(mapa, player);
    isAttacking = true;
    isGoingToAttack = false;
}

void Skeleton::updateTextureFromCeldas(Mapa& mapa, Player& player) {
    switch(attackDirection) {
        case AttackDirection::RIGHT:
            updateTextureFromCeldaAndHurtPlayer(mapa, player, fila, columna + 1);
            updateTextureFromCeldaAndHurtPlayer(mapa, player, fila, columna + 2);
            break;
        case AttackDirection::LEFT:
            updateTextureFromCeldaAndHurtPlayer(mapa, player, fila, columna - 1);
            updateTextureFromCeldaAndHurtPlayer(mapa, player, fila, columna - 2);
            break;
        case AttackDirection::DOWN:
            updateTextureFromCeldaAndHurtPlayer(mapa, player, fila + 1, columna);
            updateTextureFromCeldaAndHurtPlayer(mapa, player, fila + 2, columna);
            break;
        case AttackDirection::UP:
            updateTextureFromCeldaAndHurtPlayer(mapa, player, fila - 1, columna);
            updateTextureFromCeldaAndHurtPlayer(mapa, player, fila - 2, columna);
            break;
        default: break;
    }
}

void Skeleton::resetTextureFromCeldas(Mapa& mapa) {
    switch(attackDirection) {
        case AttackDirection::RIGHT:
            resetTextureFromCelda(mapa, fila, columna + 1);
            resetTextureFromCelda(mapa, fila, columna + 2);
            break;
        case AttackDirection::LEFT:
            resetTextureFromCelda(mapa, fila, columna - 1);
            resetTextureFromCelda(mapa, fila, columna - 2);
            break;
        case AttackDirection::DOWN:
            resetTextureFromCelda(mapa, fila + 1, columna);
            resetTextureFromCelda(mapa, fila + 2, columna);
            break;
        case AttackDirection::UP:
            resetTextureFromCelda(mapa, fila - 1, columna);
            resetTextureFromCelda(mapa, fila - 2, columna);
            break;
        default: break;
    }
}

void Skeleton::updateTextureFromCeldaAndHurtPlayer(Mapa& mapa, Player& player, int objFila, int objCol) {
    if(!(objFila < 0 || objCol < 0 || objFila >= mapDimension || objCol >= mapDimension)) {
        mapa.celdas[{objFila, objCol}]->updateSpriteTexture("celdaDano");
        if(objFila == player.getFila() && objCol == player.getColumna()) {
            player.hurt(10);
        }
    }
}

void Skeleton::resetTextureFromCelda(Mapa& mapa, int objFila, int objCol) {
    if(!(objFila < 0 || objCol < 0 || objFila >= mapDimension || objCol >= mapDimension)) {
        mapa.celdas[{objFila, objCol}]->updateSpriteTexture("celda");
    }
}

bool Skeleton::playerIsClose(Player& player) {
    return (fila - 1 == player.getFila() && columna == player.getColumna()) || (fila + 1 == player.getFila() && columna == player.getColumna()) || (columna - 1 == player.getColumna() && fila == player.getFila()) || (columna + 1 == player.getColumna() && fila == player.getFila());
}

Skeleton::AttackDirection Skeleton::guessAttackDirection(Player& player) {
    Skeleton::AttackDirection attackDirection = Skeleton::AttackDirection::NONE;
    if(fila - 1 == player.getFila() && columna == player.getColumna()) {
        attackDirection = Skeleton::AttackDirection::UP;
    }
    if(fila + 1 == player.getFila() && columna == player.getColumna()) {
        attackDirection = Skeleton::AttackDirection::DOWN;
    }
    if(columna - 1 == player.getColumna() && fila == player.getFila()) {
        attackDirection = Skeleton::AttackDirection::LEFT;
    }
    if(columna + 1 == player.getColumna() && fila == player.getFila()) {
        attackDirection = Skeleton::AttackDirection::RIGHT;
    }
    return attackDirection;
}