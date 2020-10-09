#pragma once
#include "entities/entity_base.hpp"


class Bullet : public EntityBase{
private:
    const int interval = 100000;
public:
    Bullet(const int x, const int y, Game* game);
    ~Bullet();

    void update(const int elapsed);

    void onCollision(const EntityType type);
private:
    bool move();
};
