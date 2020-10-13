#pragma once
#include <ncurses.h>

enum class WindowColor{
    WINDOW_WHITE,
    WINDOW_CYAN,
    WINDOW_MAGENTA,
    WINDOW_GREEN,
    WINDOW_YELLOW
};

inline void initColors() {
    init_pair((int)WindowColor::WINDOW_WHITE, COLOR_WHITE, -1);
    init_pair((int)WindowColor::WINDOW_CYAN, COLOR_CYAN, -1);
    init_pair((int)WindowColor::WINDOW_MAGENTA, COLOR_MAGENTA, -1);
    init_pair((int)WindowColor::WINDOW_GREEN, COLOR_GREEN, -1);
    init_pair((int)WindowColor::WINDOW_YELLOW, COLOR_YELLOW, -1);
}