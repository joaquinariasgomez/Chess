#include <iostream>
#include "tablero/Tablero.hh"
#include "Accion.hh"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <ctime>
#include <SFML/Graphics.hpp>
#include "graphics/TextureLoader.hh"

int main() {
    // create the window
    const int WIDTH = 1080;
    const int HEIGHT = 1080;
    //TextureLoader T("sample");
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My game kappa");

    sf::Texture texture = (new TextureLoader("sample"))->getTexture();
    sf::Texture texture2 = (new TextureLoader("test"))->getTexture();
    sf::Sprite sprite;
    sf::Sprite sprite2;
    sprite.setTexture(texture);
    sprite2.setTexture(texture2);
    sprite.setPosition(sf::Vector2f(0.f, 0.f)); // absolute position
    sprite2.setPosition(sf::Vector2f(0.f, 0.f)); // absolute position
    sprite.setScale(sf::Vector2f(10.f, 10.f)); // absolute scale factor
    sprite2.setScale(sf::Vector2f(10.f, 10.f)); // absolute scale factor
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
        // window.draw(...);
        window.draw(sprite);
        window.draw(sprite2);

        // end the current frame
        window.display();
    }
}