#include "Celda.hh"
#include "items/Roca.hh"
#include "items/Pared.hh"
#include "items/Agujero.hh"
#include "items/AgujeroRelleno.hh"

Celda::Celda(int fila, int columna, int itemValor): fila_(fila), columna_(columna), sprite(new SpriteManager(fila, columna, "celda")) {
    switch(itemValor) {
        case 1: items.push_back(new Pared(fila, columna)); break;
        case 2: items.push_back(new Roca(fila, columna)); break;
        case 3: items.push_back(new Agujero(fila, columna)); break;
        case 4: items.push_back(new AgujeroRelleno(fila, columna)); break;
        case -1:
        default: items.push_back(NULL);
    }
}

void Celda::removeItem(Item* item) {
    auto it = items.begin();
    for(auto const& itemIt: items) {
        if(item == itemIt) {
            items.erase(it);
        }
        ++it;
    }
    // Check if vector is empty, then push NULL
    if(items.empty()) items.push_back(NULL);
}

void Celda::draw(sf::RenderWindow& window) const {
    // First render cell
    window.draw(sprite->getSprite());
    // Render items
    for(auto const& item: items) {
        if(item != NULL) {
            item->draw(window);
        }
    }
}