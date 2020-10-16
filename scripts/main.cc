#include <iostream>
#include "tablero/Tablero.hh"
#include "Accion.hh"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <ctime>
#include <SFML/Window.hpp>

void readUserMovementAndMove(Tablero& tablero) {
    // Leer acción
    std::string mov;
    std::cin >> mov;
    
    //Crear acción que contiene a tablero
    Accion accion(mov);
    accion.move(tablero);
}

void readAIMovementAndMove(Tablero& tablero) {
    bool puedoMover = false;
    std::string movChar = "";
    while(!puedoMover) {
        int coordX = std::rand()%8 + 1;
        int coordY = std::rand()%8 + 1;
        int mov = std::rand()%4 + 1;
        switch(mov) {
            case 1: movChar = "a"; break;
            case 2: movChar = "w"; break;
            case 3: movChar = "s"; break;
            case 4: movChar = "d"; break;
            default: break;
        }
        movChar = std::to_string(coordX) + std::to_string(coordY) + movChar;
        Accion accion(movChar);
        int error = accion.move(tablero);
        puedoMover = (error != -1);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
}

int main() {
    /*srand(time(NULL));
    Tablero tablero;
    while(true) {
        // Printear tablero
        std::cout << tablero << std::endl;
        std::cout << "\n=================================\n" << std::endl;
        
        //readUserMovementAndMove(tablero);
        readAIMovementAndMove(tablero);
    }*/
    sf::Window window(sf::VideoMode(800, 600), "Chess haha");
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}