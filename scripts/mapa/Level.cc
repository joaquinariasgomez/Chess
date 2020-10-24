#include "Level.hh"

Level::Level(Mapa* mapa): mapa(mapa) {

}

void Level::draw(sf::RenderWindow& window) const {
    // Dibujar nivel no es más que dibujar mapa y luego las entidades enemigas o amigas que estén sobre él
    mapa->draw(window);
    // Draw entities
    
}