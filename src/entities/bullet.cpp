#include "entities/bullet.hpp"
#include "game.hpp"


// Public methods

Bullet::Bullet(const int x, const int y, Game* game):
    EntityBase(x, y, ACS_BULLET, EntityType::BULLET, game)
{}

Bullet::~Bullet() {}

void Bullet::update(const int elapsed) {
    EntityBase::update(elapsed);

    if (current_elapsed_time > interval) {
        if (!move()) setDead();
        current_elapsed_time -= interval;
    }
}

void Bullet::onCollision(const EntityType) {
    setDead();
}

// Private methods

bool Bullet::move() {
    return changePos(x + 1, y);
}