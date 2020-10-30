#pragma once
#include <vector>
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
        std::vector<std::pair<int, int>> getSkeletonCoords() const;
        int getMapDimension() const {return mapDimension;}
    private:
        void initializeMatrix(std::ifstream& file, int guessedWidthDimension, std::string line, char delimiter);
        int guessWidthDimension(std::string line, char delimiter);
        int** matrix;
        int mapDimension;
        std::pair<int, int> objCoords;
        std::vector<std::pair<int, int>> skeletonCoords;
};