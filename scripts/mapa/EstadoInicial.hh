#pragma once
#include <string>

class EstadoInicial {
    public:
        static int getElementFromCelda(int i, int j);   //devuelve la información de la ficha cifrada (-1 -> no hay ficha, 1 ficha de 1 tipo, 2 ficha de otro tipo, etc)
        static std::pair<int,int> guessDimensions(std::string fileName, std::string delimiter);
};