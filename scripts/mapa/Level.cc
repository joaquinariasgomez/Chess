#include "Level.hh"

Level::Level(int levelId): mapa(new Mapa(levelId)), levelId(levelId) {

}

void Level::draw(sf::RenderWindow& window) const {
    // Dibujar nivel no es más que dibujar mapa y luego las entidades enemigas o amigas que estén sobre él
    mapa->draw(window);
    // Draw entities

}