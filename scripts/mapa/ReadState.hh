#pragma once
#include <string>

class ReadState {
    public:
        static int getElementFromCelda(int levelId, int i, int j);   //devuelve la información de la ficha cifrada (-1 -> no hay ficha, 1 ficha de 1 tipo, 2 ficha de otro tipo, etc)
    private:
        static int guessWidthDimension(std::string line, char delimiter);
};