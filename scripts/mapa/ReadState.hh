#pragma once
#include <string>
#include <fstream>
#include <iostream>

class ReadState {
    public:
        ReadState();
        void inspectElements(int levelId);
        int getElementFromCelda(int i, int j);
        std::pair<int, int> getPlayerCoords() const;
        std::pair<int, int> getObjCoords() const;
    private:
        void initializeMatrix(std::ifstream& file, int guessedWidthDimension, std::string line, char delimiter);
        int guessWidthDimension(std::string line, char delimiter);
        int** matrix;
        int dim;
        std::pair<int, int> objCoords;
};