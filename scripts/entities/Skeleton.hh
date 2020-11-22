#pragma once
#include "Entity.hh"

class Skeleton: public Entity {
    public:
        enum AttackDirection {
            NONE,
            RIGHT,
            LEFT,
            UP,
            DOWN
        };
        Skeleton(float vida, int fila, int columna, int mapDimension);
        void draw(sf::RenderWindow& window) const;
        void hurt(float damage);
        void die();
        bool isDead() const;
        void update(Player& player, Mapa& mapa);
    private:
        ItemSprite* isGoingToAttackSprite;
        bool isGoingToAttack;
        bool isAttacking; //Esto debería pintar las celdas que sean atacadas con una textura
        AttackDirection attackDirection;
        AttackDirection lastAttackDirection;
        const int MAX_FRAMES_WITHOUT_ATTACKING = 3; //2 + (1 de isGoingToAttack)
        int currentFramesWithoutAttacking;

        void attackIfPlayerIsClose(Player& player, Mapa& mapa);
        void updateFramesWithoutAttacking();
        void performAttack(Mapa& mapa, Player& player);
        void updateTextureFromCeldas(Mapa& mapa, Player& player);
        void resetTextureFromCeldas(Mapa& mapa, AttackDirection latestAttackDirection);
        void resetTextureFromCelda(Mapa& mapa, int objFila, int objCol);
        void updateTextureFromCeldaAndHurtPlayer(Mapa& mapa, Player& player, int objFila, int objCol);
        bool playerIsClose(Player& player);
        AttackDirection guessAttackDirection(Player& player);

        Mapa* mapa;
};