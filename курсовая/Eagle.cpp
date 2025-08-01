#include "Eagle.h"

Eagle::Eagle()
    : AirTransport("Орёл", 8) {
}

double Eagle::getDistanceReduction(double distance) const {
    return distance * 0.94; // Всегда 6% сокращение
}

double Eagle::calculateTime(double distance) const {
    return getDistanceReduction(distance) / speed;
}