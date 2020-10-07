#include "game.hpp"
#include <unistd.h>

using namespace std;

void curses_init() {
    initscr();
    refresh();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

int main(int argc, char** argv) {
    // Initializing ncurses library
    curses_init();

    // Delay of the game
    const int delay = 1000;

    Game game;
    // Main game cycle
    while(!game.isOver()) {
        game.update();
        game.draw();
        usleep(delay);
    }

    endwin();
    return 0;
}