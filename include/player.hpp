#pragma once

class Game;


// Player class, associated with game class
class Player {
private:
    // Player x, y coordinates on game window screen
    int x, y;
    // Player character
    const char player_ch = '#';

    // Game pointer
    Game* game;

public:
    Player(const int x, const int y, Game* game);
    ~Player();

    // Change current position by vector {dx, dy}
    bool go(const int dx, const int dy);
private:
    // Change position to new
    bool changePos(const int nx, const int ny);
};