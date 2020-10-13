#include "game.hpp"
#include <unistd.h>

using namespace std;

void curses_init() {
    setlocale(LC_CTYPE, "");
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    start_color();
    use_default_colors();
}

int main(int argc, char** argv) {
    // Initializing ncurses library
    curses_init();
    initColors();


    // Delay of the game
    const int delay = 1000;

    Game game;
    // Main game cycle
    while(!game.isOver()) {
        game.update(delay);
        game.draw();
        usleep(delay);
    }

    endwin();
    return 0;
}