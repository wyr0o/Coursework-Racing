#pragma once
#include "Transport.h"

class Race {
private:
    double distance;
    Transport** transports; 
    int transportCount;
    int transportCapacity;
    bool groundRace;
    bool airRace;

    void resizeTransportArray();

public:
    Race(double distance, bool ground, bool air);
    ~Race();
    void addTransport(Transport* transport);
    bool canAddTransport(Transport* transport) const;
    Transport* getTransport(int index) const;
    int getTransportCount() const;
    double getDistance() const;
    bool isGroundRace() const;
    bool isAirRace() const;
    void runRace() const;
};