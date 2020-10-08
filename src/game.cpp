#include "game.hpp"


// Public methods

Game::Game():
    entity_manager(this),
    is_over(false),
    is_stopped(false),
    elapsed_time(0)
{
    initWin();
    entity_manager.addEntity(width / 2, height / 2, EntityType::PLAYER);
}

Game::~Game() {}

void Game::update(const int elapsed) {
    if (!is_stopped) {
        elapsed_time += elapsed;

        // Generate new layer of asteroids if interval is passed
        if (elapsed_time > asteroid_interval) {
            generateAsteroids();
            elapsed_time -= asteroid_interval;
        }

        // Update all entities
        entity_manager.update(elapsed);
        
        if (entity_manager.getPlayer()->isDead()) {
            // Stop the game
            stop();
            // Show game over screen
            gameOverScreen();
        }
    }
    else {  // If game is stopped
        char ans = getch();
        switch (ans) {
            case 'y':
                restart();
                break;
            case 'n':
                exit();
                break;
        }
    }

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
    return is_over;
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

void Game::stop() {
    is_stopped = true;
}

void Game::resume() {
    is_stopped = false;
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

    std::string win_title = " ilshat25/alien ";
    // Set title
    int carriage_title = width / 2 - win_title.size() / 2;
    for (char ch : win_title)
        win[height-1][carriage_title++] = ch;
}

void Game::gameOverScreen() {
    // Set border
    for(int col = 1; col < width - 1; ++col) {
        win[height / 2 - 2][col] = '#';
        win[height / 2 - 1][col] = ' ';
        win[height / 2    ][col] = ' ';
        win[height / 2 + 1][col] = ' ';
        win[height / 2 + 2][col] = '#';
    }

    std::string game_over_title = "Game over";
    // Set title
    int carriage_title = width / 2 - game_over_title.size() / 2;
    for (char ch : game_over_title)
        win[height / 2 - 1][carriage_title++] = ch;

    std::string restart_title = "Do you want to restart? y/n";
    // Set restart offer
    carriage_title = width / 2 - restart_title.size() / 2;
    for (char ch : restart_title)
        win[height / 2 + 1][carriage_title++] = ch;

}

void Game::generateAsteroids() {
    for (int row = 1; row < height - 1; ++row) if(rand() % 100 >= 80)
        entity_manager.addEntity(width - 1, row, EntityType::ASTEROID);
}

void Game::restart() {
    // Release all entities
    entity_manager.clear();
    // Clear win
    win.clear();
    // Init win
    initWin();
    // Add player
    entity_manager.addEntity(width / 2, height / 2, EntityType::PLAYER);
    // Set elapsed time to 0
    elapsed_time = 0;
    // Resume the game
    resume();
}

void Game::exit() {
    is_over = true;
}
