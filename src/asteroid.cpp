#include "asteroid.hpp"
#include "game.hpp"


// Public methods

Asteroid::Asteroid(const int x, const int y, Game* game):
    Entity(x, y, ACS_DIAMOND, EntityType::ASTEROID, game)
{}

Asteroid::~Asteroid() {}

void Asteroid::update(const int elapsed) {
    Entity::update(elapsed);

    if (elapsed_time > interval) {
        if (!move()) setDead();
        elapsed_time -= interval;
    }
}

void Asteroid::onCollision(const EntityType type) {
    setDead();
}

// Private methods

bool Asteroid::move() {
    return changePos(x - 1, y);
}