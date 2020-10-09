#include "entity_manager.hpp"
#include "game.hpp"


// Public methods

EntityManager::EntityManager(Game* game):
    player(nullptr),
    game(game)
{}

EntityManager::~EntityManager() {
    releaseAll();
}

void EntityManager::addEntity(const int x, const int y, const EntityType type) {
    EntityBase* entity_to_push = nullptr;
    
    switch(type) {
        case EntityType::PLAYER:
            // If player already exists
            if (player)
                delete player;
            player = entity_to_push = new Player(x, y, game);
            break;
        case EntityType::BULLET:
            entity_to_push = new Bullet(x, y, game);
            break;
        case EntityType::ASTEROID:
            entity_to_push = new Asteroid(x, y, game);
            break;
    }

    to_add.push_back(entity_to_push);
}

EntityBase* EntityManager::getPlayer() {
    return player;
}

void EntityManager::update(const int elapsed) {
    releaseDead();
    for (EntityBase* entity : entities)
        entity->update(elapsed);

    // Add entities
    for (EntityBase* entity : to_add)
        entities.push_back(entity);
    to_add.clear();

    resolveCollisions();
}

void EntityManager::clear() {
    releaseAll();
    player = nullptr;
}

// Private methods

void EntityManager::releaseAll() {
    for (EntityBase* entity : entities){
        entity->kill();
        delete entity;
    }
    entities.clear();
}

void EntityManager::releaseDead() {
    for(auto iter = entities.begin(); iter != entities.end();) {
        EntityBase* entity = *iter;
        if (entity->isDead()) {
            iter = entities.erase(iter);
            entity->kill();
            delete entity;
        }
        else
            ++iter;
    }
}

void EntityManager::resolveCollisions() {
    for (EntityBase* entity_1 : entities)
        for (EntityBase* entity_2 : entities) 
            if (entity_1 != entity_2 && entity_1->getCoords() == entity_2->getCoords()) {
                entity_1->onCollision(entity_2->getType());
                entity_2->onCollision(entity_1->getType());               
            }
}