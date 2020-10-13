#include "entities/asteroid.hpp"
#include "game.hpp"


// Public methods

Asteroid::Asteroid(const int x, const int y, Game* game):
    EntityBase(x, y, ACS_BLOCK, WindowColor::WINDOW_YELLOW, EntityType::ASTEROID, game)
{}

Asteroid::~Asteroid() {}

void Asteroid::update(const int elapsed) {
    EntityBase::update(elapsed);

    if (current_elapsed_time > interval) {
        if (!move()) setDead();
        current_elapsed_time -= interval;
    }
}

void Asteroid::onCollision(const EntityType type) {
    setDead();
}

// Private methods

bool Asteroid::move() {
    return changePos(x - 1, y);
}