#include "player.hpp"
#include "game.hpp"

// Public methods

Player::Player(const int x, const int y, Game* game):
    Entity(x, y, ACS_BOARD, EntityType::PLAYER, game)
{}

Player::~Player() {}

bool Player::go(const int dx, const int dy) {
    return changePos(x + dx, y + dy);
}

void Player::update(const int elapsed) {
    Entity::update(elapsed);

    const int ch = getch();
    if (ch != -1)
        std::cerr << "|" << ch << "|" << '\n';
    switch(ch) {
        case KEY_UP:
            go(0, -1);
            break;
        case KEY_DOWN:
            go(0, 1);
            break;
        case KEY_LEFT:
            go(-1, 0);
            break;
        case KEY_RIGHT:
            go(1, 0);
            break;
        case ' ':    // Space bar
            shoot();
            break;
    }
}

void Player::onCollision(const EntityType type) {
    setDead();
}

// Private methods

void Player::shoot() {
    std::cerr << "Shoot!\n";
    game->getEntityManager()->addEntity(x + 1, y, EntityType::BULLET);
}
