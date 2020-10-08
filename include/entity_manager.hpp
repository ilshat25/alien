#pragma once
#include <vector>

#include "entity.hpp"

// Types of entities
enum class EntityType {
    PLAYER,
    BULLET,
    ASTEROID
};

// Manage all entities on the game
class EntityManager {
private:
    // Vector of entities
    std::vector<Entity*> entities;
    // Vector of entities to add
    std::vector<Entity*> to_add;

    // Palyer entity or null if it doesn't exist
    Entity* player;
    // Game reference
    Game* game;

public:
    EntityManager(Game * game);
    ~EntityManager();

    // Add entity to the manager
    void addEntity(const int x, const int y, const EntityType type);
    // Returns player reference or null if it doesn't exist
    Entity* getPlayer();

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