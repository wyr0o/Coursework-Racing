#pragma once
#include "AirTransport.h"

class Broom : public AirTransport {
public:
    Broom();
    double calculateTime(double distance) const override;
    double getDistanceReduction(double distance) const override;
};