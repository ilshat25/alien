#pragma once
#include "entity.hpp"


class Asteroid: public Entity {
private:
    const int interval = 200000;
public:
    Asteroid(const int x, const int y, Game* game);
    ~Asteroid();

    void update(const int elapsed);
private:
    bool move();
};