#include "AgujeroRelleno.hh"

AgujeroRelleno::AgujeroRelleno(int fila, int columna, int mapDimension): Item(fila, columna, mapDimension, "agujeroRelleno", 4) {

}

void AgujeroRelleno::draw(sf::RenderWindow& window) const {
    window.draw(sprite->getSprite());
}