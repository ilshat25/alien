#include "entities/ammunition.hpp"
#include "game.hpp"


// Public methods

Ammunition::Ammunition(const int x, const int y, Game* game):
    EntityBase(x, y, ACS_DIAMOND, WindowColor::WINDOW_GREEN, EntityType::AMMUNITION, game)
{}

Ammunition::~Ammunition() {}

void Ammunition::update(const int elapsed_time) {
    EntityBase::update(elapsed_time);

    if (current_elapsed_time > step_interval) {
        if (!move()) setDead();
        current_elapsed_time -= step_interval;
    }
}

void Ammunition::onCollision(const EntityType type) {
    setDead();
}

// Private methods

bool Ammunition::move() {
    return changePos(x - 1, y);
}
