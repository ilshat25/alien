#include "entity.hpp"
#include "game.hpp"

// Public methods

Entity::Entity(const int x, const int y, const int entity_ch, Game* game):
    GameObject(x, y, entity_ch, game),
    is_dead(false)
{}

Entity::~Entity() {}

bool Entity::isDead() {
    return is_dead;
}

void Entity::kill() {
    game->clearCh(x, y);
}

// Protected methods

void Entity::setDead() {
    is_dead = true;
}
