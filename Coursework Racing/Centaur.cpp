#include "Centaur.h"

Centaur::Centaur()
    : GroundTransport("Кентавр", 15, 8) {
}

double Centaur::calculateTime(double distance) const {
    double time = distance / speed;
    int restCount = static_cast<int>(time / getMoveTime());
    return time + restCount * 2.0; 
}