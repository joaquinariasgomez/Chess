#include "Tablero.hh"
#include "EstadoInicial.hh"

Tablero::Tablero() {
    for(int i=0; i<dimension_; ++i) {
        for(int j=0; j<dimension_; ++j) {
            celdas[{i,j}] = new Celda(i,j,EstadoInicial::getElementFromCelda(i,j));
        }
    }
}

std::ostream &Tablero::printObject(std::ostream &os) {
  for(int i=0; i<dimension_; ++i) {
    os << "+---";
  }
  os << "+" << std::endl;

  for(int i=0; i<dimension_; ++i) {
    for(int j=0; j<dimension_; ++j) {
      os << "| " << celdas[{i,j}]->print() << " ";
    }
    os << "|" << std::endl;
    for(int i=0; i<dimension_; ++i) {
      os << "+---";
    }
    os << "+" << std::endl;
  }
  return os;
}