#include "GroundTransport.h"

GroundTransport::GroundTransport(const std::string& name, double speed, double moveTime)
    : Transport(name, speed), moveTime(moveTime) {
}

bool GroundTransport::isGround() const {
    return true;
}

bool GroundTransport::isAir() const {
    return false;
}

double GroundTransport::getMoveTime() const {
    return moveTime;
}