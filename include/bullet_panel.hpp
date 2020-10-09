#pragma once
#include "base/window_element.hpp"


class BulletPanel: public WindowElement {
private:
    int bullet_count = 0;
public:
    BulletPanel();
    ~BulletPanel();

    void update(const int elapsed_time, const int bullet_count);
};