#include "entities/entity_base.hpp"
#include "game.hpp"

// Public methods

EntityBase::EntityBase(const int x, const int y, const int entity_ch, const WindowColor win_color, EntityType type, Game* game):
    GameElement(x, y, entity_ch, win_color, game),
    is_dead(false),
    type(type)
{}

EntityBase::~EntityBase() {}

std::pair<int, int> EntityBase::getCoords() {
    return std::make_pair(x, y);
}

EntityType EntityBase::getType() {
    return type;
}

bool EntityBase::isDead() {
    return is_dead;
}

void EntityBase::kill() {
    game->clearCh(x, y);
}

// Protected methods

void EntityBase::setDead() {
    is_dead = true;
}
