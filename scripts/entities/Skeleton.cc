#include "Skeleton.hh"

Skeleton::Skeleton(float vida, int fila, int columna, int mapDimension): Entity(vida, "skeleton", fila, columna, mapDimension) {

}

void Skeleton::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}

void Skeleton::hurt(float damage) {
    vida -= damage;
    if(vida < 0) {
        vida = 0;
    }
    // Update texture according to vida
    //
    if(vida == 0) {
        // Skeleton dies
    }
}