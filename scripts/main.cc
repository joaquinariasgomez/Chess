#include <iostream>
#include "mapa/Mapa.hh"
#include <SFML/Graphics.hpp>
#include "graphics/SpriteManager.hh"
#include "graphics/Window.hh"
#include "entities/Player.hh"

const int DIM = 6;
int Mapa::dimension{DIM};

void draw(sf::RenderWindow& window, Mapa& mapa, Player& player) {
    mapa.draw(window);
    player.draw(window);
}

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(Window::getWindowWidth(), Window::getWindowHeight()), "My game kappa", sf::Style::Close);

    Mapa mapa;
    Player player;
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
            if (event.type == sf::Event::EventType::KeyPressed){
                player.evaluate(event, mapa);
            }
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        draw(window, mapa, player);

        // end the current frame
        window.display();
    }
}