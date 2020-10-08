#include "entity.hpp"
#include "game.hpp"

// Public methods

Entity::Entity(const int x, const int y, const int entity_ch, EntityType type, Game* game):
    GameObject(x, y, entity_ch, game),
    is_dead(false),
    type(type)
{}

Entity::~Entity() {}

std::pair<int, int> Entity::getCoords() {
    return std::make_pair(x, y);
}

EntityType Entity::getType() {
    return type;
}

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
