#include "game.hpp"

// Public methods

Game::Game():
    WindowElement(" ilshat25/alien ", 0, 0, 61, 21),
    entity_manager(this),
    is_over(false),
    is_stopped(false)
{
    score = 0;
    asteroid_generation_chance = 50;
    ammuniation_generation_chance = 50;
    resetField();
    entity_manager.addEntity(win_width / 2, win_height / 2, EntityType::PLAYER);
}

Game::~Game() {}

void Game::update(const int elapsed) {
    WindowElement::update(elapsed);
    if (!is_stopped) {

        // Update all entities
        entity_manager.update(elapsed);

        // Generate new layer of asteroids if interval is passed
        if (current_elapsed_time > asteroid_interval) {
            generateAsteroids();
            current_elapsed_time -= asteroid_interval;
        }

        // Upadete bullet panel
        const int bullet_count = static_cast<Player*>(entity_manager.getPlayer())->getBulletCount();
        bullet_panel.update(elapsed, bullet_count);

        score_panel.update(elapsed, score);

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
    score_panel.draw();
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

void Game::addScore(const int dscore) {
    score += dscore;
}

void Game::nullifyScore() {
    score = 0;
}

// Private methods

void Game::gameOverScreen() {
    // Set border
    for(int col = 1; col < width; ++col) {
        field[win_height / 2 - 2][col] = '#';
        field[win_height / 2 - 1][col] = ' ';
        field[win_height / 2    ][col] = ' ';
        field[win_height / 2 + 1][col] = ' ';
        field[win_height / 2 + 2][col] = '#';
        color_pairs[win_height / 2 - 2][col] = COLOR_PAIR(WindowColor::WINDOW_WHITE);
        color_pairs[win_height / 2 - 1][col] = COLOR_PAIR(WindowColor::WINDOW_WHITE);
        color_pairs[win_height / 2    ][col] = COLOR_PAIR(WindowColor::WINDOW_WHITE);
        color_pairs[win_height / 2 + 1][col] = COLOR_PAIR(WindowColor::WINDOW_WHITE);
        color_pairs[win_height / 2 + 2][col] = COLOR_PAIR(WindowColor::WINDOW_WHITE);
    }

    std::string game_over_title = "Game over";
    // Set title
    int carriage_title = win_width / 2 - game_over_title.size() / 2;
    for (char ch : game_over_title)
        setCh(carriage_title++, win_height / 2 - 1, ch, WindowColor::WINDOW_WHITE);

    std::string game_score_title = "Your score: " + std::to_string(score) + ", time: " + std::to_string(total_elapsed_time / 1000000.0) + "s";
    // Set score
    carriage_title = win_width / 2 - game_score_title.size() / 2;
    for (char ch : game_score_title)
        setCh(carriage_title++, win_height / 2, ch, WindowColor::WINDOW_CYAN);


    std::string restart_title = "Do you want to restart? y/n";
    // Set restart offer
    carriage_title = win_width / 2 - restart_title.size() / 2;
    for (char ch : restart_title)
        setCh(carriage_title++, win_height / 2 + 1, ch, WindowColor::WINDOW_WHITE);
}

void Game::generateAsteroids() {
    for (int row = 1; row < height; ++row) {
        const int num = rand() % 100;
        if (rand() % 2) {
            // Try generate asteroid
            if (num < asteroid_generation_chance)
                entity_manager.addEntity(width - 1, row, EntityType::ASTEROID);
        }
        else {
            // Try generate ammuniation
            if (num < ammuniation_generation_chance)
            entity_manager.addEntity(width - 1, row, EntityType::AMMUNITION);
        }
    }
    ++generation_count;
    if (generation_count % 10 == 9) {
        // Add difficulty every 10 gerated lines
        ++asteroid_generation_chance;
        --ammuniation_generation_chance;
    }
}

void Game::restart() {
    resetTime();
    resetField();
    nullifyScore();
    entity_manager.clear();
    entity_manager.addEntity(width / 2, height / 2, EntityType::PLAYER);
    resume();
}

void Game::exit() {
    is_over = true;
}
