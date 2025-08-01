#pragma once
#include "GroundTransport.h"

class Camel : public GroundTransport {
public:
    Camel();
    double calculateTime(double distance) const override;
};