#include "Transport.h"

Transport::Transport(const std::string& name, double speed)
    : name(name), speed(speed) {
}

std::string Transport::getName() const {
    return name;
}

double Transport::getSpeed() const {
    return speed;
}