#pragma once
#include <string>

class Transport {
protected:
    std::string name;
    double speed;
public:
    Transport(const std::string& name, double speed);
    virtual ~Transport() {}
    virtual double calculateTime(double distance) const = 0;
    std::string getName() const;
    double getSpeed() const;
    virtual bool isGround() const = 0;
    virtual bool isAir() const = 0;
};