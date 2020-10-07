#include "player.hpp"
#include "game.hpp"

// Public methods

Player::Player(const int x, const int y, Game* game):
    GameObject(x, y, ACS_BOARD, game)
{}

Player::~Player() {}

bool Player::go(const int dx, const int dy) {
    return changePos(x + dx, y + dy);
}

void Player::update(const int elapsed) {
    GameObject::update(elapsed);

    const int ch = getch();

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

void Player::shoot() {
    game->getEntityManager()->addEntity(x + 1, y, EntityType::BULLET);
}
