#include <ncurses.h>
#include <iostream>
#include <vector>
#include <string>

#include "player.hpp"


// Main game class, controls the whole game
class Game {
private:
    // Width and height of the game window
    const int width = 61;
    const int height = 21;

    // Game window characters
    std::vector<std::string> win = {
        "+-----------------------------------------------------------+",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "|                                                           |",
        "+------------------ ilshat25/alien -------------------------+"
    };

    // Player
    Player player;


public:
    Game();
    ~Game();

    void update();
    void draw();

    // Check for game over
    bool isOver();
    // Check for border at position (x, y)
    bool isBorder(const int x, const int y);

    // Set character ch at position (x, y)
    bool setCh(const int x, const int y, const char ch);
    // Clear position (x, y)
    bool clearCh(const int x, const int y);
};
