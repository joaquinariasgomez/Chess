#include "Pincho.hh"

Pincho::Pincho(int fila, int columna, int mapDimension, int gravedad): gravedad(gravedad), Item(fila, columna, mapDimension, "pincho"+std::to_string(gravedad), 6) {

}

void Pincho::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}

void Pincho::hurt(Player& player) {
    int damage;
    switch(gravedad) {
        case 1: damage = 10; break;
        case 2: damage = 20; break;
        case 3: damage = 30; break;
    }
    player.hurt(damage);
    sprite->updateTexture("pincho"+std::to_string(gravedad)+"sangre");
}