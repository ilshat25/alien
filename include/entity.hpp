#pragma once
#include <utility>

#include "game_object.hpp"

enum class EntityType;

class Entity: public GameObject {
private:
    // Dead flag
    bool is_dead;
    // Entity type
    EntityType type;
public:
    Entity(const int x, const int y, int entity_ch, EntityType type, Game* game);
    virtual ~Entity();

    // Returns coordinates of entity
    std::pair<int, int> getCoords();
    // Returns type of entity
    EntityType getType();

    // Checks is dead flag
    bool isDead();
    // Remove entity from the screen
    void kill();

    // Actions in case of collision with Entity
    virtual void onCollision(const EntityType type) = 0;
protected:
    // Sets dead flag to true
    void setDead();
};