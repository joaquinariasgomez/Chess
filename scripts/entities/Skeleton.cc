#include "Skeleton.hh"
#include "Player.hh"
#include <iostream>

Skeleton::Skeleton(float vida, int fila, int columna, int mapDimension): Entity(vida, "skeleton", fila, columna, mapDimension), isGoingToAttackSprite(new ItemSprite("isGoingToAttack", fila, columna, mapDimension)), isGoingToAttack(false), isAttacking(false) {
}

void Skeleton::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
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
    std::cout << "IM UPDATING" << std::endl;
    // Comprobar si tengo jugador al alcance, y ponerme en estado "isGoingToAttack"
    
}