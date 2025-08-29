#pragma once
#include "Transport.h"

class AirTransport : public Transport {
public:
    AirTransport(const std::string& name, double speed);
    bool isGround() const override;
    bool isAir() const override;
    virtual double getDistanceReduction(double distance) const = 0;
};