#include "base/game_element.hpp"
#include "game.hpp"

GameElement::GameElement(const int x, const int y, const int element_ch, Game* game):
    x(x),
    y(y),
    element_ch(element_ch),
    game(game)
{
    changePos(x, y);
}

GameElement::~GameElement() {}

// Protected methods

bool GameElement::changePos(const int nx, const int ny) {
    if (game->isBorder(nx, ny))
        return false;
    game->clearCh(x, y);
    x = nx;
    y = ny;
    game->setCh(x, y, element_ch);
    return true;
}