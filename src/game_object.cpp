#include "game_object.hpp"
#include "game.hpp"

GameObject::GameObject(const int x, const int y, const int object_ch, Game* game):
    x(x),
    y(y),
    object_ch(object_ch),
    game(game)
{
    elapsed_time = 0;
}

GameObject::~GameObject() {}

void GameObject::update(const int elapsed) {
    elapsed_time += elapsed;
}

// Protected methods

bool GameObject::changePos(const int nx, const int ny) {
    if (game->isBorder(nx, ny))
        return false;
    game->clearCh(x, y);
    x = nx;
    y = ny;
    game->setCh(x, y, object_ch);
    return true;
}