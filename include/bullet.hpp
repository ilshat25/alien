#pragma once
#include "entity.hpp"

class Bullet : public Entity{
private:
    const int interval = 100000;
public:
    Bullet(const int x, const int y, Game* game);
    ~Bullet();

    void update(const int elapsed);
    bool move();
};
