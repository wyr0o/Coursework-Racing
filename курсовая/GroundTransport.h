#pragma once
#include "Transport.h"

class GroundTransport : public Transport {
protected:
    double moveTime;
public:
    GroundTransport(const std::string& name, double speed, double moveTime);
    bool isGround() const override;
    bool isAir() const override;
    double getMoveTime() const;
};