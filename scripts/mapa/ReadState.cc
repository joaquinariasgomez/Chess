#include "ReadState.hh"
#include <iostream>
#include <fstream>
#include <string>

int ReadState::guessWidthDimension(std::string line, char delimiter) {
    int width =0;
    size_t pos;
    while((pos = line.find(delimiter)) != std::string::npos) {
        ++width;
        do {
            line.erase(0, 1);   // Eliminar primer elemento de la línea
        } while(line[0] == delimiter);
    }
    return width + 1;   // Cuenta los espacios, asi que devolver el número de espacios más 1
}

int ReadState::getElementFromCelda(int levelId, int i, int j) {
    // Leer del fichero la posición i, j y devolver el valor que contenga, que ya está cifrado
    // Buscar el identificador "mapa" dentro de level.txt
    std::string fileName = "../levels/level"+std::to_string(levelId)+".txt";
    std::ifstream file(fileName);
    char delimiter = ' ';
    std::string mapKeyword = "mapa";

    // Find mapKeyword
    bool mapFound = false;
    int guessedWidthDim = 0;
    std::string line;
    while(std::getline(file, line)) {
        if(mapFound) {
            guessedWidthDim = guessWidthDimension(line, delimiter);
            break;
        }
        else {
            if(line.find(mapKeyword) != std::string::npos) {
                mapFound = true;
                continue;
            }
        }
    }
    if(!mapFound) {std::cout << "ERROR in level"+std::to_string(levelId)+", "+mapKeyword+" NOT FOUND"; exit(-1);}
    int rowCount = 0;
    int matrix[guessedWidthDim][guessedWidthDim];
    int a = 0, b = 0;
    do {
        // Analizar fila
        std::string token;
        size_t pos;
        while((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            matrix[a][b++] = std::stoi(token);
            do {
                line.erase(0, 1);   // Eliminar primer elemento de la línea
            } while(line[0] == delimiter);
        }
        matrix[a][b] = std::stoi(line);
        ++a;
        b = 0;

        ++rowCount;
    } while(std::getline(file, line) && rowCount < guessedWidthDim);

    return matrix[i][j];
}