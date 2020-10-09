#pragma once
#include "entities/entity_base.hpp"


// Player class, associated with game class
class Player : public EntityBase {
private:
    const int max_bullet_count = 3;
    int bullet_count;
public:
    Player(const int x, const int y, Game* game);
    ~Player();

    bool go(const int dx, const int dy);
    void update(const int elapsed);

    void onCollision(const EntityType type);

    void addBullet();
    int getBulletCount();
private:
    void shoot();
};