#include "Level.hh"

Level::Level(int levelId): levelId(levelId), state(new ReadState()) {
    state->inspectElements(levelId);
    mapa = new Mapa(levelId, state);
}

void Level::draw(sf::RenderWindow& window) const {
    // Dibujar nivel no es más que dibujar mapa y luego las entidades enemigas o amigas que estén sobre él
    mapa->draw(window);
    // Draw entities

}