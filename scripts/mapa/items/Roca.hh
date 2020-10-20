#include "Item.hh"
#include "../Mapa.hh"
#include <string>

class Roca: public Item {
    public:
        Roca(int fila, int columna);
        void draw(sf::RenderWindow& window) const;
        int move(Mapa& mapa, std::string direction);
    private:
        int moveLeft(Mapa& mapa);
        int moveRight(Mapa& mapa);
        int moveUp(Mapa& mapa);
        int moveDown(Mapa& mapa);
        void updateSpritePosition();
        int fila;
        int columna;
};