#pragma once
#include "GroundTransport.h"

class AllTerrainBoots : public GroundTransport {
public:
    AllTerrainBoots();
    double calculateTime(double distance) const override;
};