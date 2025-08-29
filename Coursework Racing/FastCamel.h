#pragma once
#include "GroundTransport.h"

class FastCamel : public GroundTransport {
public:
    FastCamel();
    double calculateTime(double distance) const override;
};