#include "Eagle.h"

Eagle::Eagle()
    : AirTransport("���", 8) {
}

double Eagle::getDistanceReduction(double distance) const {
    return distance * 0.94; // ������ 6% ����������
}

double Eagle::calculateTime(double distance) const {
    return getDistanceReduction(distance) / speed;
}