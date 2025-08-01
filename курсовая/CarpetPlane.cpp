#include "CarpetPlane.h"

CarpetPlane::CarpetPlane()
    : AirTransport("Ковёр-самолёт", 10) {
}

double CarpetPlane::getDistanceReduction(double distance) const {
    if (distance < 1000) return distance;
    if (distance < 5000) return distance * 0.97;
    if (distance < 10000) return distance * 0.90;
    return distance * 0.95;
}

double CarpetPlane::calculateTime(double distance) const {
    return getDistanceReduction(distance) / speed;
}