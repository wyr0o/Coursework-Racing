#include "Camel.h"

Camel::Camel()
    : GroundTransport("Верблюд", 10, 30) {
}

double Camel::calculateTime(double distance) const {
    double time = distance / speed;
    int restCount = static_cast<int>(time / getMoveTime());

    if (restCount == 0) return time;

    double restTime = 5; 
    if (restCount > 1) {
        restTime += (restCount - 1) * 8;
    }

    return time + restTime;
}