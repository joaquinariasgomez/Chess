#pragma once
#include <string>

class EstadoInicial {
    public:
        static std::string getElementFromCelda(int i, int j);   //devuelve la información de la ficha cifrada (-1 -> no hay ficha, 1 ficha de 1 tipo, 2 ficha de otro tipo, etc)
    private:
        EstadoInicial() {}
};