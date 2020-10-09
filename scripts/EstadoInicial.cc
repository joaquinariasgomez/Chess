#include "EstadoInicial.hh"
#include <iostream>
#include <fstream>

std::string EstadoInicial::getElementFromCelda(int i, int j) {
    //Leer del fichero la posición i, j y devolver el valor que contenga, que ya está cifrado
    std::ifstream file("estadoInicial.txt");
    std::string str;
    while (std::getline(file, str)) {
        std::cout << str << "\n";
    }
    return "pepe";
}