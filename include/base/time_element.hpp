#pragma once


class TimeElement {
protected:
    int current_elapsed_time;
    int total_elapsed_time;
public:
    TimeElement();
    virtual ~TimeElement() = 0;

    virtual void update(const int elapsed_time);
protected:
    void resetTime();
};
