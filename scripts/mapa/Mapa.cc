#include "Mapa.hh"
#include "EstadoInicial.hh"

Mapa::Mapa(int dimension): dimension_(dimension), sprite(new SpriteManager(0, 0, dimension, "background")) {
    for(int i=0; i<dimension_; ++i) {
        for(int j=0; j<dimension_; ++j) {
            celdas[{i,j}] = new Celda(i,j,EstadoInicial::getElementFromCelda(i,j),dimension);
        }
    }
}

void Mapa::draw(sf::RenderWindow& window) const {
    // First render background
    window.draw(sprite->getSprite());   //Sprite background
    // Render celdas
    for(auto const& [_, celda] : celdas) {
        celda->draw(window);
    }
}