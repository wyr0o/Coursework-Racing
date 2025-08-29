#include "AllTerrainBoots.h"

AllTerrainBoots::AllTerrainBoots()
    : GroundTransport("Ботинки-вездеходы", 6, 60) {
}

double AllTerrainBoots::calculateTime(double distance) const {
    double time = distance / speed;
    int restCount = static_cast<int>(time / getMoveTime());

    if (restCount == 0) return time;

    double restTime = 10.0; 
    if (restCount > 1) {
        restTime += (restCount - 1) * 5.0; 
    }

    return time + restTime;
}