#include "base/time_element.hpp"


// Public methods

TimeElement::TimeElement():
    current_elapsed_time(0),
    total_elapsed_time(0)
{}

void TimeElement::update(const int elapsed_time) {
    current_elapsed_time += elapsed_time;
    total_elapsed_time += elapsed_time;
}

TimeElement::~TimeElement() {}

// Protected methods

void TimeElement::resetTime() {
    current_elapsed_time = 0;
    total_elapsed_time = 0;
}
