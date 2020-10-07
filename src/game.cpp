#include "game.hpp"

Game::Game():
    player(width / 2, height / 2, this)
{
}

Game::~Game() {
    std::cout << "Game destructor\n";
}

void Game::update() {
    const int ch = getch();

    switch(ch) {
        case KEY_UP:
            player.go(0, -1);
            break;
        case KEY_DOWN:
            player.go(0, 1);
            break;
        case KEY_LEFT:
            player.go(-1, 0);
            break;
        case KEY_RIGHT:
            player.go(1, 0);
            break;
    }
    refresh();
}

void Game::draw() {
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

bool Game::setCh(const int x, const int y, const char ch) {
    if (!isBorder(x, y)) {
        win[y][x] = ch;
        return true;
    }
    return false;
}

bool Game::clearCh(const int x, const int y) {
    return setCh(x, y, ' ');
}