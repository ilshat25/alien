#pragma once
#include "base/window_element.hpp"


class ScorePanel: public WindowElement {
private:
    int score = 0;
public:
    ScorePanel();
    ~ScorePanel();

    void update(const int elapsed_time, const int score);
};
