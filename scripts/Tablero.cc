#include "Tablero.hh"

std::ostream &Tablero::printObject(std::ostream &os) {
  os << "This is my very nice message: " << std::endl;
  os << dimension_;

  return os;
}