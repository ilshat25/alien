#include "game.hpp"

// Public methods

Game::Game():
    WindowElement(" ilshat25/alien ", 0, 0, 61, 21),
    entity_manager(this),
    is_over(false),
    is_stopped(false)
{
    resetField();
    entity_manager.addEntity(win_width / 2, win_height / 2, EntityType::PLAYER);
}

Game::~Game() {}

void Game::update(const int elapsed) {
    WindowElement::update(elapsed);
    if (!is_stopped) {

        // Generate new layer of asteroids if interval is passed
        if (current_elapsed_time > asteroid_interval) {
            generateAsteroids();
            current_elapsed_time -= asteroid_interval;
        }

        // Update all entities
        entity_manager.update(elapsed);

        // Upadete bullet panel
        const int bullet_count = static_cast<Player*>(entity_manager.getPlayer())->getBulletCount();
        bullet_panel.update(elapsed, bullet_count);

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
    WindowElement::draw();
    bullet_panel.draw();
}

bool Game::isOver() {
    return is_over;
}

EntityManager* Game::getEntityManager() {
    return &entity_manager;
}

void Game::stop() {
    is_stopped = true;
}

void Game::resume() {
    is_stopped = false;
}

// Private methods

void Game::gameOverScreen() {
    // Set border
    for(int col = 1; col < width - 1; ++col) {
        field[win_height / 2 - 2][col] = '#';
        field[win_height / 2 - 1][col] = ' ';
        field[win_height / 2    ][col] = ' ';
        field[win_height / 2 + 1][col] = ' ';
        field[win_height / 2 + 2][col] = '#';
    }

    std::string game_over_title = "Game over";
    // Set title
    int carriage_title = win_width / 2 - game_over_title.size() / 2;
    for (char ch : game_over_title)
        field[win_height / 2 - 1][carriage_title++] = ch;

    std::string restart_title = "Do you want to restart? y/n";
    // Set restart offer
    carriage_title = win_width / 2 - restart_title.size() / 2;
    for (char ch : restart_title)
        field[win_height / 2 + 1][carriage_title++] = ch;

}

void Game::generateAsteroids() {
    for (int row = 1; row < height - 1; ++row) if(rand() % 100 >= 80)
        entity_manager.addEntity(width - 1, row, EntityType::ASTEROID);
}

void Game::restart() {
    resetTime();
    resetField();
    entity_manager.clear();
    entity_manager.addEntity(width / 2, height / 2, EntityType::PLAYER);
    resume();
}

void Game::exit() {
    is_over = true;
}
