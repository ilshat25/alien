#pragma once
#include <utility>
#include "base/game_element.hpp"


enum class EntityType;

class EntityBase: public GameElement {
private:
    bool is_dead;
    
    EntityType type;

public:
    EntityBase(const int x, const int y, int entity_ch, const WindowColor color, EntityType type, Game* game);
    virtual ~EntityBase();

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