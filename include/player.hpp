#pragma once
#include "entity.hpp"


// Player class, associated with game class
class Player : public Entity {
public:
    Player(const int x, const int y, Game* game);
    ~Player();

    // Change current position by vector {dx, dy}
    bool go(const int dx, const int dy);
    void update(const int elapsed);

    void onCollision(const EntityType type);
private:
    void shoot();
};