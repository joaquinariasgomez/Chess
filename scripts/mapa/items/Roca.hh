#include "Item.hh"
#include <string>

class Roca: public Item {
    public:
        Roca(int fila, int columna);
        void draw(sf::RenderWindow& window) const;
        int move(std::string direction);
    private:
        int moveLeft();
        int moveRight();
        int moveUp();
        int moveDown();
};