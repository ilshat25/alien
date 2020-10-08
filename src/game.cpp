#include "game.hpp"


// Public methods

Game::Game():
    entity_manager(this),
    elapsed_time(0)
{
    initWin();
    entity_manager.addEntity(width / 2, height / 2, EntityType::PLAYER);
}

Game::~Game() {}

void Game::update(const int elapsed) {
    elapsed_time += elapsed;

    if (elapsed_time > asteroid_interval) {
        generateAsteroids();
        elapsed_time -= asteroid_interval;
    }

    entity_manager.update(elapsed);
}

void Game::draw() {
    refresh();
    for (int col = 0; col < width; ++col)
        for (int row = 0; row < height; ++row) {
            move(row, col);
            addch(win[row][col]);
        }
}

bool Game::isOver() {
    return false;
}

bool Game::isBorder(const int x, const int y) {
    if (x <= 0 || x >= width - 1 || y <= 0 || y >= height - 1)
        return true;
    return false;
}

bool Game::isFree(const int x, const int y) {
    if (x <= 0 || x >= width - 1 || y <= 0 || y >= height - 1)
        return false;
    return win[y][x] == ' ';
}

EntityManager* Game::getEntityManager() {
    return &entity_manager;
}

bool Game::setCh(const int x, const int y, const int ch) {
    if (!isBorder(x, y)) {
        win[y][x] = ch;
        return true;
    }
    return false;
}

bool Game::clearCh(const int x, const int y) {
    return setCh(x, y, ' ');
}

// Private methods

void Game::initWin() {
    // Allocate memory fow win
    win.resize(height, std::vector<int>(width));

    // Set border
    for (int row = 0; row < height; ++row)
        for (int col = 0; col < width; ++col)
            if (row == 0 && col == 0)
                // Left top corner
                win[row][col] = ACS_ULCORNER;
            else if (row == 0 && col == width - 1)
                // Right top corner
                win[row][col] = ACS_URCORNER; 
            else if (row == height - 1 && col == 0)
                // Left bottom corner
                win[row][col] = ACS_LLCORNER;
            else if (row == height - 1 && col == width - 1)
                // Right bottom corner
                win[row][col] = ACS_LRCORNER;
            else if (row == 0 || row == height - 1)
                // Horizontal line
                win[row][col] = ACS_HLINE;
            else if (col == 0 || col == width - 1)
                // Vertical line
                win[row][col] = ACS_VLINE;
            else
                // Void
                win[row][col] = ' ';

    // Set title
    int carriage_title = width / 2 - win_title.size() / 2;
    for (char ch : win_title)
        win[height-1][carriage_title++] = ch;
}

void Game::generateAsteroids() {
    for (int row = 1; row < height - 1; ++row) if(rand() % 100 >= 80)
        entity_manager.addEntity(width - 1, row, EntityType::ASTEROID);
}
