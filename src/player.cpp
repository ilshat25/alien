#include "player.hpp"
#include "game.hpp"


// Public methods

Player::Player(const int x, const int y, Game* game):
    x(x),
    y(y),
    game(game)
{
    game->setCh(x, y, player_ch);
}

Player::~Player() {}

bool Player::go(const int dx, const int dy) {
    return changePos(x + dx, y + dy);
}


// Private methods

bool Player::changePos(const int nx, const int ny) {
    if (game->isBorder(nx, ny))
        return false;
    game->clearCh(x, y);
    x = nx;
    y = ny;
    game->setCh(x, y, player_ch);
    return true;
}