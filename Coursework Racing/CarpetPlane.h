#pragma once
#include "AirTransport.h"

class CarpetPlane : public AirTransport {
public:
    CarpetPlane();
    double calculateTime(double distance) const override;
    double getDistanceReduction(double distance) const override;
};