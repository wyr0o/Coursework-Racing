#include "FastCamel.h"

FastCamel::FastCamel()
    : GroundTransport("Верблюд-быстроход", 40, 10) {
}

double FastCamel::calculateTime(double distance) const {
    double time = distance / speed;
    int restCount = static_cast<int>(time / getMoveTime());

    if (restCount == 0) return time;

    double restTime = 5.0; // Первый отдых
    if (restCount > 1) {
        restTime += 6.5; // Второй отдых
        if (restCount > 2) {
            restTime += (restCount - 2) * 8.0; // Последующие отдыхи
        }
    }

    return time + restTime;
}