#pragma once
#include "entities/entity_base.hpp"


class Asteroid: public EntityBase {
private:
    int interval = 200000;
public:
    Asteroid(const int x, const int y, Game* game);
    ~Asteroid();

    void update(const int elapsed);
    
    void onCollision(const EntityType type);
private:
    bool move();
};