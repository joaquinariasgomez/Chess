#include <iostream>
//#include "mapa/Mapa.hh"
#include "mapa/StatusBar.hh"
#include "mapa/Level.hh"
#include <SFML/Graphics.hpp>
#include "graphics/SpriteManager.hh"
#include "graphics/Window.hh"
#include "entities/Player.hh"

const int DIM = 6;
const float MAX_VIDA = 100;
float Player::maxVida{MAX_VIDA};
int Mapa::dimension{DIM};

void draw(sf::RenderWindow& window, Level& level, StatusBar& statusBar, Player& player) {
    statusBar.draw(window);
    level.draw(window);     // Draw map and entities
    player.draw(window);
}

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(Window::getMapWidth(), Window::getMapHeight() + Window::getBarHeight()), "My game kappa", sf::Style::Close);

    StatusBar statusBar;
    Player player(&statusBar);

    Level currentLevel(1);   // Load level 1
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
                player.evaluateEvent(event, currentLevel);
            }
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        draw(window, currentLevel, statusBar, player);

        // end the current frame
        window.display();
    }
}