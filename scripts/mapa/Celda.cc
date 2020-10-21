#include "Celda.hh"
#include "items/Roca.hh"
#include "items/Pared.hh"
#include "items/Agujero.hh"
#include "items/AgujeroRelleno.hh"

Celda::Celda(int fila, int columna, int itemValor): fila_(fila), columna_(columna), sprite(new SpriteManager(fila, columna, "celda")) {
    switch(itemValor) {
        case 1: item = new Pared(fila, columna); break;
        case 2: item = new Roca(fila, columna); break;
        case 3: item = new Agujero(fila, columna); break;
        case 4: item = new AgujeroRelleno(fila, columna); break;
        case -1:
        default: item = NULL;
    }
}

void Celda::draw(sf::RenderWindow& window) const {
    // First render cell
    window.draw(sprite->getSprite());
    // Render item
    if(item != NULL) {
        item->draw(window);
    }
}