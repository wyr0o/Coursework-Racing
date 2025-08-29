#pragma once
#include "AirTransport.h"

class Eagle : public AirTransport {
public:
    Eagle();
    double calculateTime(double distance) const override;
    double getDistanceReduction(double distance) const override;
};