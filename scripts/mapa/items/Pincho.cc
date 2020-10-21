#include "Pincho.hh"

Pincho::Pincho(int fila, int columna, int gravedad): gravedad(gravedad), Item(fila, columna, "pincho"+std::to_string(gravedad), 6) {

}

void Pincho::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}

void Pincho::hurt(Player& player) {
    int damage;
    switch(gravedad) {
        case 1: damage = 20; break;
        case 2: damage = 30; break;
        case 3: damage = 40; break;
    }
    player.hurt(damage);
    sprite->updateTexture("pincho"+std::to_string(gravedad)+"sangre");
}