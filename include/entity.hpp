#pragma once
#include "game_object.hpp"


class Entity: public GameObject {
private:
    // Dead flag
    bool is_dead;

public:
    Entity(const int x, const int y, int entity_ch, Game* game);
    virtual ~Entity();

    // Checks is dead flag
    bool isDead();
    // Remove entity from the screen
    void kill();
protected:
    // Sets dead flag to true
    void setDead();
};