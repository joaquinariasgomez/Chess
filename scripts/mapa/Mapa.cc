#include "Mapa.hh"
#include "ReadState.hh"

Mapa::Mapa(): sprite(new SpriteManager(0, 0, "background")) {
    for(int i=0; i<dimension; ++i) {
        for(int j=0; j<dimension; ++j) {
            celdas[{i,j}] = new Celda(i,j,ReadState::getElementFromCelda(i,j));
        }
    }
}

void Mapa::draw(sf::RenderWindow& window) const {
    // First render background
    window.draw(sprite->getSprite());   //Sprite background
    // Render cells
    for(auto const& [coords, celda] : celdas) {
        celda->draw(window);
    }
}