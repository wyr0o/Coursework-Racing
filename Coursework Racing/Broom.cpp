#include "Broom.h"

Broom::Broom()
    : AirTransport("�����", 20) {
}

double Broom::getDistanceReduction(double distance) const {
    int reductionPercent = static_cast<int>(distance / 1000);
    return distance * (1 - reductionPercent / 100.0);
}

double Broom::calculateTime(double distance) const {
    return getDistanceReduction(distance) / speed;
}