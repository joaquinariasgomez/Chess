#include "Mapa.hh"

Mapa::Mapa(int levelId, ReadState* state, std::pair<int, int> punteroCeldaObjetivo): sprite(new BackgroundSprite("background")) {
    dimension = state->getMapDimension();
    for(int i=0; i<dimension; ++i) {
        for(int j=0; j<dimension; ++j) {
            bool isObjetivo = (punteroCeldaObjetivo == std::make_pair(i,j));
            celdas[{i,j}] = new Celda(i,j,dimension,state->getElementFromCelda(i, j), isObjetivo);
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