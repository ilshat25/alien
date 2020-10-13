#pragma once
#include <vector>

#include "entities/entity_base.hpp"
#include "entities/bullet.hpp"
#include "entities/asteroid.hpp"
#include "entities/player.hpp"
#include "entities/ammunition.hpp"

// Types of entities
enum class EntityType {
    PLAYER,
    BULLET,
    ASTEROID,
    AMMUNITION
};

// Manage all entities on the game
class EntityManager {
private:
    // Vector of entities
    std::vector<EntityBase*> entities;
    // Vector of entities to add
    std::vector<EntityBase*> to_add;

    // Palyer entity or null if it doesn't exist
    EntityBase* player;
    // Game reference
    Game* game;

public:
    EntityManager(Game * game);
    ~EntityManager();

    // Add entity to the manager
    void addEntity(const int x, const int y, const EntityType type);
    // Returns player reference or null if it doesn't exist
    EntityBase* getPlayer();

    void update(const int elapsed);

    // Release all entities
    void clear();
private:
    // Release all entities and associated memory
    void releaseAll();
    // Release all dead entities and associated memory
    void releaseDead();

    // Check and resolve collision among entities
    void resolveCollisions();
};