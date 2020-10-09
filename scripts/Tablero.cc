#include "Tablero.hh"

Tablero::Tablero() {
    for(int i=0; i<dimension_; ++i) {
        for(int j=0; j<dimension_; ++j) {
            celdas[{i,j}] = new Celda(i,j);
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
  std::cout << EstadoInicial::getElementFromCelda(0,0) << std::endl;
  return os;
}