#include "SpriteManager.hh"

// Varios TIPOS de sprites:
// * Background     DONE
// * StatusBar -> Elementos como Vida o Stamina     DONE
// * Items -> Cualquier elemento renderizado en una casilla (necesita de fila y columna)

/*SpriteManager::SpriteManager(int fila, int columna, std::string textureName, int mapDimension, bool weapon): mapDimension(mapDimension) {
    texture = TextureLoader::getTexture(textureName);
    sprite.setTexture(texture);

    sf::Vector2u texSize = texture.getSize();
    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

        if(weapon) {
            renderWeapon(fila, columna);
        }
}*/


/*void SpriteManager::renderWeapon(int fila, int columna) {
    sf::Vector2u texSize = texture.getSize();

    unsigned int textureWidth = texSize.x;
    unsigned int textureHeight = texSize.y;

    float spriteWidth = (float)Window::getMapWidth() / (float)mapDimension;
    float spriteHeight = (float)Window::getMapHeight() / (float)mapDimension;
    sprite.setPosition(sf::Vector2f(columna * spriteHeight, fila * spriteWidth + Window::getBarHeight()));
    sprite.setScale(sf::Vector2f(spriteWidth / (float)textureWidth, spriteHeight / (float)textureHeight));
}*/