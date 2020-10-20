#include <iostream>
#include "mapa/Mapa.hh"
#include "Accion.hh"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <ctime>
#include <SFML/Graphics.hpp>
#include "graphics/SpriteManager.hh"
#include "graphics/Window.hh"

const int DIM = 6;
int Mapa::dimension{DIM};

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(Window::getWindowWidth(), Window::getWindowHeight()), "My game kappa");

    Mapa mapa;
    // run the program as long as the window is open
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

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        mapa.draw(window);

        // end the current frame
        window.display();
    }
}