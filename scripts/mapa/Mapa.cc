#include "Mapa.hh"
#include "EstadoInicial.hh"

Mapa::Mapa(int dimension): dimension_(dimension), sprite(new SpriteManager(0, 0, dimension, "sample")) {
    for(int i=0; i<dimension_; ++i) {
        for(int j=0; j<dimension_; ++j) {
            celdas[{i,j}] = new Celda(i,j,EstadoInicial::getElementFromCelda(i,j));
        }
    }
}