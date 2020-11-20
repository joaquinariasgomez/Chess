#include "Skeleton.hh"
#include "Player.hh"
#include <iostream>

Skeleton::Skeleton(float vida, int fila, int columna, int mapDimension): Entity(vida, "skeleton", fila, columna, mapDimension), isGoingToAttackSprite(new ItemSprite("test", fila, columna, mapDimension)), isGoingToAttack(false), isAttacking(false), attackDirection(AttackDirection::NONE) {
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

void Skeleton::update(Player& player) {
    attackIfPlayerIsClose(player);
}

void Skeleton::attackIfPlayerIsClose(Player& player) {
    if(isGoingToAttack) {
        performAttack();
    }
    else {
        if(playerIsClose(player)) {
            isGoingToAttack = true;
            attackDirection = guessAttackDirection(player);
        }
    }
}

void Skeleton::performAttack() {
    std::cout << "ATACANDO " << attackDirection << std::endl;
    isGoingToAttack = false;
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