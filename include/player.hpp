#pragma once
#include "game_object.hpp"


// Player class, associated with game class
class Player : GameObject {
public:
    Player(const int x, const int y, Game* game);
    ~Player();

    // Change current position by vector {dx, dy}
    bool go(const int dx, const int dy);
    void update(const int elapsed);
private:
    void shoot();
};