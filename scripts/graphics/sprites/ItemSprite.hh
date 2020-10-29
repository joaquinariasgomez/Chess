#pragma once
#include "SpriteManager.hh"

class ItemSprite: public SpriteManager {
    public:
        ItemSprite(std::string textureName, int fila, int columna, int mapDimension);
        void updateTexture(std::string textureName);
        void updatePosition(int fila, int columna);
    private:
        int mapDimension;
};