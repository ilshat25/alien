#pragma once
#include <ncurses.h>
#include <iostream>
#include <vector>
#include <string>

#include "entity_manager.hpp"

// Main game class, controls the whole game
class Game {
private:
    // Width and height of the game window
    const int width = 61;
    const int height = 21;

    // Game window characters
    std::vector<std::vector<int>> win;

    // Entity Manager
    EntityManager entity_manager;

    // Game over flag
    bool is_over;
    // Stop game flag
    bool is_stopped;

    // Asteroid interval
    const int asteroid_interval = 1000000;
    int elapsed_time;
public:
    Game();
    ~Game();

    void update(const int elapsed);
    void draw();

    // Check for game over
    bool isOver();
    // Check for border at position (x, y)
    bool isBorder(const int x, const int y);
    // Check for free cell at position (x, y)
    bool isFree(const int x, const int y);

    EntityManager* getEntityManager();

    // Set character ch at position (x, y)
    bool setCh(const int x, const int y, const int ch);
    // Clear position (x, y)
    bool clearCh(const int x, const int y);

    // Stop the game
    void stop();
    // Resume the game
    void resume();
private:
    // Initialize game window by border and title
    void initWin();
    // Game over screen
    void gameOverScreen();

    // Generate new layer of asteroids
    void generateAsteroids();
    
    // Restart the game
    void restart();
    // Exit from the game
    void exit();
};
