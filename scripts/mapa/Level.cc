#include "Level.hh"
#include "../entities/Player.hh"
#include "../entities/Skeleton.hh"

Level::Level(int levelId): levelId(levelId), state(new ReadState()) {
    state->inspectElements(levelId);

    punteroCeldaObjetivo = state->getObjCoords();
    mapa = new Mapa(levelId, state, punteroCeldaObjetivo);
    initiateSkeletons(state->getSkeletonCoords());
}

void Level::draw(sf::RenderWindow& window) const {
    // Dibujar nivel no es más que dibujar mapa y luego las entidades enemigas o amigas que estén sobre él
    mapa->draw(window);
    // Draw entities
    for(auto const& entity: entities) {
        entity->draw(window);
    }
}

void Level::initiateSkeletons(std::vector<std::pair<int, int>> skeletonCoords) {    // For every skeleton found, give it 100 life
    int mapDimension = mapa->dimension;
    for(auto const& skeletonCoord: skeletonCoords) {
        entities.push_back(new Skeleton(90, skeletonCoord.first, skeletonCoord.second, mapDimension));
    }
}

bool Level::hasEntity(int desiredFila, int desiredCol) const {
    bool result = false;
    for(auto const& entity: entities) {
        if(entity->fila == desiredFila && entity->columna == desiredCol) {
            result = true;
        }
    }
    return result;
}

bool Level::hurtEntity(int desiredFila, int desiredCol, float damage) {
    bool killedEntity = false;
    
    std::vector<Entity*>::iterator it = entities.begin();
    for(auto const& entity: entities) {
        if(entity->fila == desiredFila && entity->columna == desiredCol) {
            entity->hurt(damage);
            if(entity->isDead()) {
                entities.erase(it);
                killedEntity = true;
            }
        }
        ++it;
    }
    return killedEntity;
}

void Level::updateEntities(Player& player) {
    for(auto const& entity: entities) {
        entity->update(player);
    }
}