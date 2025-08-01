#include "AirTransport.h"

AirTransport::AirTransport(const std::string& name, double speed)
    : Transport(name, speed) {
}

bool AirTransport::isGround() const {
    return false;
}

bool AirTransport::isAir() const {
    return true;
}