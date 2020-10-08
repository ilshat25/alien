#include "bullet.hpp"
#include "game.hpp"
#include "ncurses.h"


// Public methods

Bullet::Bullet(const int x, const int y, Game* game):
    Entity(x, y, ACS_BULLET, EntityType::BULLET, game)
{}

Bullet::~Bullet() {}

void Bullet::update(const int elapsed) {
    Entity::update(elapsed);

    if (elapsed_time > interval) {
        if (!move()) setDead();
        elapsed_time -= interval;
    }
}

void Bullet::onCollision(const EntityType) {
    setDead();
}

// Private methods

bool Bullet::move() {
    return changePos(x + 1, y);
}
