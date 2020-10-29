#pragma once
#include "SpriteManager.hh"

class StatusBarSprite: public SpriteManager {
    public:
        StatusBarSprite(std::string textureName, std::string textureType);
        void updateLife(float life);
    private:
        void renderBackground();
        void renderLife(float currVida);    //TODO: convertir a publico y eliminar updateLife
        void renderNoLife();
        void renderLifeCover();
};