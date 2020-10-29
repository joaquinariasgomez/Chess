#include "Celda.hh"
#include "items/Roca.hh"
#include "items/Pared.hh"
#include "items/Agujero.hh"
#include "items/AgujeroRelleno.hh"
#include "items/Pincho.hh"

Celda::Celda(int fila, int columna, int mapDimension, int itemValor, bool objetivo): fila_(fila), columna_(columna) {
    if(objetivo) {
        sprite = new ItemSprite("celdaObjetivo", fila, columna, mapDimension);
    }
    else {
        sprite = new ItemSprite("celda", fila, columna, mapDimension);
    }
    switch(itemValor) {
        case 1: items.push_back(new Pared(fila, columna, mapDimension)); break;
        case 2: items.push_back(new Roca(fila, columna, mapDimension)); break;
        case 3: items.push_back(new Agujero(fila, columna, mapDimension)); break;
        case 4: items.push_back(new AgujeroRelleno(fila, columna, mapDimension)); break;
        case 6: items.push_back(new Pincho(fila, columna, mapDimension, 1)); break;
        case 7: items.push_back(new Pincho(fila, columna, mapDimension, 2)); break;
        case 8: items.push_back(new Pincho(fila, columna, mapDimension, 3)); break;
        case 0:
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
