#pragma once
#include "GroundTransport.h"

class Centaur : public GroundTransport {
public:
    Centaur();
    double calculateTime(double distance) const override;
};