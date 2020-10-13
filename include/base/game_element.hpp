#pragma once
#include "base/time_element.hpp"
#include "base/window_color.hpp"

class Game;

class GameElement : public TimeElement {
protected:
    // Coordinates on game window screen
    int x, y;
    // Game object character
    const int element_ch;
    WindowColor win_color;
    // Game pointer
    Game* game;

public:
    GameElement(const int x, const int y, const int element_ch, const WindowColor win_color, Game* game);
    virtual ~GameElement() = 0;

protected:
    bool changePos(const int nx, const int ny);
};
