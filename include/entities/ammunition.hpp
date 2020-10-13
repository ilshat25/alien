#pragma once
#include "entities/entity_base.hpp"


class Ammunition: public EntityBase {
private:
    const int step_interval = 200000;
public:
    Ammunition(const int x, const int y, Game* game);
    ~Ammunition();

    void update(const int elapsed);
    
    void onCollision(const EntityType type);
private:
    bool move();
};
