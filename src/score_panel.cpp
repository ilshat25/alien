#include "score_panel.hpp"


ScorePanel::ScorePanel():
    WindowElement(" Score ", 63, 6, 11, 5),
    score(-1)
{}

ScorePanel::~ScorePanel() {}

void ScorePanel::update(const int elapsed_time, const int score) {
    if (score != this->score) {
        resetField();
        this->score = score;
        const std::string score_str = std::to_string(score);
        const int y_center = win_height / 2;
        const int x_begin = win_width / 2 - score_str.size() / 2;
        for (int i = 0; i < score_str.size(); ++i)
            setCh(x_begin + i, y_center, score_str[i], WindowColor::WINDOW_CYAN);
    }
}

