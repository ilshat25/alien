#pragma once
#include <vector>
#include <string>
#include <ncurses.h>
#include "base/time_element.hpp"
#include "base/window_color.hpp"


class WindowElement: public TimeElement {
protected:
    const std::string win_title;
    const int win_x, win_y;
    const int win_width, win_height;
    const int width, height;
    WINDOW* win;
    std::vector<std::vector<int>> field;
    std::vector<std::vector<int>> color_pairs;
public:
    WindowElement(const std::string title, const int x, const int y, const int width, const int height);
    virtual ~WindowElement();

    virtual void draw();

    virtual bool isBorder(const int x, const int y);
    virtual bool isFree(const int x, const int y);

    virtual bool setCh(const int x, const int y, const int ch, const WindowColor win_color);
    virtual bool clearCh(const int x, const int y);
protected:
    virtual void resetField();
};