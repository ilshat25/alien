#include "base/window_element.hpp"


// Public methods

WindowElement::WindowElement(const std::string title, const int x, const int y, const int width, const int height):
    win_title(title),
    win_x(x), win_y(y),
    win_width(width), win_height(height),
    width(width - 1), height(height - 1)
{
    win = newwin(win_height, win_width, win_y, win_x);
    resetField();
}

WindowElement::~WindowElement() {
    delwin(win);
}

void WindowElement::draw() {
    for (int row = 0; row < win_height; ++row)
        for (int col = 0; col < win_width; ++col) {
            wmove(win, row, col);
            waddch(win, field[row][col]);
        }
    wrefresh(win);
}

bool WindowElement::isBorder(const int x, const int y) {
    if (x == 0 || x == win_width - 1 || y == 0 || y == win_height - 1)
        return true;
    return false;
}

bool WindowElement::isFree(const int x, const int y) {
    if (x <= 0 || x >= win_width - 1 || y <= 0 || y >= win_height - 1)
        return false;
    return field[y][x] == ' ';
}

bool WindowElement::setCh(const int x, const int y, const int ch) {
    if (isFree(x, y) && !isBorder(x, y)) {
        field[y][x] = ch;
        return true;
    }
    return false;
}

bool WindowElement::clearCh(const int x, const int y) {
    if (x <= 0 || x >= win_width - 1 || y <= 0 || y >= win_height - 1 || isBorder(x, y))
        return false;
    field[y][x] = ' ';
    return true;
}

// Protected methods

void WindowElement::resetField() {
    // Allocate memory fow win
    field.resize(win_height, std::vector<int>(win_width));

    // Set border
    for (int row = 0; row < win_height; ++row)
        for (int col = 0; col < win_width; ++col)
            if (row == 0 && col == 0)
                // Left top corner
                field[row][col] = ACS_ULCORNER;
            else if (row == 0 && col == win_width - 1)
                // Right top corner
                field[row][col] = ACS_URCORNER; 
            else if (row == win_height - 1 && col == 0)
                // Left bottom corner
                field[row][col] = ACS_LLCORNER;
            else if (row == win_height - 1 && col == win_width - 1)
                // Right bottom corner
                field[row][col] = ACS_LRCORNER;
            else if (row == 0 || row == win_height - 1)
                // Horizontal line
                field[row][col] = ACS_HLINE;
            else if (col == 0 || col == win_width - 1)
                // Vertical line
                field[row][col] = ACS_VLINE;
            else
                // Void
                field[row][col] = ' ';

    // Set title
    int carriage_title = win_width / 2 - win_title.size() / 2;
    for (char ch : win_title)
        field[win_height-1][carriage_title++] = ch;
}