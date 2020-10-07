#pragma once

class Game;

class GameObject {
protected:
    // Coordinates on game window screen
    int x, y;
    // Game object character
    const int object_ch;
    // Game elaped time
    int elapsed_time;

    // Game pointer
    Game* game;

public:
    GameObject(const int x, const int y, const int object_ch, Game* game);
    virtual ~GameObject();

    virtual void update(const int elapsed);
protected:
    bool changePos(const int nx, const int ny);
};
