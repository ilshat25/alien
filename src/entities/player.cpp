#include "entities/player.hpp"
#include "game.hpp"

// Public methods

Player::Player(const int x, const int y, Game* game):
    EntityBase(x, y, ACS_RARROW, WindowColor::WINDOW_CYAN, EntityType::PLAYER, game),
    bullet_count(3)
{}

Player::~Player() {}

bool Player::go(const int dx, const int dy) {
    return changePos(x + dx, y + dy);
}

void Player::update(const int elapsed) {
    EntityBase::update(elapsed);
    
    changePos(x, y);
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

void Player::onCollision(const EntityType type) {
    switch (type)
    {
    case EntityType::AMMUNITION:
        addBullet();
        break;
    default:
        setDead();
        break;
    }
}


int Player::getBulletCount() {
    return bullet_count;
}

// Private methods

void Player::shoot() {
    if (bullet_count > 0) {
        game->getEntityManager()->addEntity(x + 1, y, EntityType::BULLET);
        --bullet_count;
    }
}

void Player::addBullet() {
    if (bullet_count < max_bullet_count) ++bullet_count;
}
