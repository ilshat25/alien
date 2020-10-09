#include "bullet_panel.hpp"


BulletPanel::BulletPanel():
    WindowElement(" Bullets ", 63, 0, 11, 5),
    bullet_count(0)
{}

BulletPanel::~BulletPanel() {}

void BulletPanel::update(const int elapsed_time, const int bullet_count) {
    if (bullet_count != this->bullet_count) {
        resetField();
        this->bullet_count = bullet_count;
        const int y_center = win_height / 2;
        const int bullet_string_size = bullet_count * 2 - 1;
        const int x_begin = win_width / 2 - bullet_string_size / 2;
        for (int i = 0; i < bullet_count; ++i)
            setCh(x_begin + 2 * i, y_center, ACS_DIAMOND);
    }
}

