#pragma once
#include "Entity.hh"

class Skeleton: public Entity {
    public:
        Skeleton(float vida, int fila, int columna, int mapDimension);
        void draw(sf::RenderWindow& window) const;
        void hurt(float damage);
        bool isDead() const;
        void update(Player& player);
        // Cada vez que mueva, pasarle la referencia de Jugador para saber a dónde dirigirse y a
        // quien atacar en caso de modificar ese objeto, similar a Roca.hh/.cc
    private:
        ItemSprite* isGoingToAttackSprite;
        bool isGoingToAttack;
        bool isAttacking; //Esto debería pintar las celdas que sean atacadas con una textura
};