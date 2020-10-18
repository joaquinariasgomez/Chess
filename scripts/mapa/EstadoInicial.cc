#include "EstadoInicial.hh"
#include <iostream>
#include <fstream>
#include <string>

std::pair<int,int> EstadoInicial::guessDimensions(std::string fileName, std::string delimiter) {
    int filas = 0;
    int columnas = 0;
     std::ifstream file(fileName);

    std::string line;
    while (std::getline(file, line)) {
        ++columnas;

        size_t pos = 0;
        filas = 0;
        while((pos = line.find(delimiter)) != std::string::npos) {
            ++filas;
            line.erase(0, pos + delimiter.length());
        }
        ++filas;
    }
    return std::pair<int,int>(filas, columnas);
}

int EstadoInicial::getElementFromCelda(int i, int j) {
    //Leer del fichero la posición i, j y devolver el valor que contenga, que ya está cifrado
    std::string fileName = "../estados/estadoInicial.txt";
    std::ifstream file(fileName);
    std::string delimiter = " ";
    std::pair<int,int> dimensions = EstadoInicial::guessDimensions(fileName, delimiter);
    int filas = dimensions.first;
    int columnas = dimensions.second;
    
    int matrix[filas][columnas];

    std::string line;
    int a = 0, b = 0;
    while (std::getline(file, line)) {
        //std::cout << line << "\n";
        size_t pos = 0;
        std::string token;
        while((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0,pos);
            matrix[a][b] = std::stoi(token);
            line.erase(0, pos + delimiter.length());
            ++b;
        }
        matrix[a][b] = std::stoi(line);
        ++a;
        b = 0;
    }
    return matrix[i][j];
}