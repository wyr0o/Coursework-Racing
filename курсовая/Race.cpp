#include "Race.h"
#include<iostream>
#include <algorithm>

Race::Race(double distance, bool ground, bool air)
    : distance(distance), groundRace(ground), airRace(air),
    transportCount(0), transportCapacity(2) {
    transports = new Transport * [transportCapacity];
}

Race::~Race() {
    for (int i = 0; i < transportCount; ++i) {
        delete transports[i];
    }
    delete[] transports;
}

void Race::resizeTransportArray() {
    transportCapacity *= 2;
    Transport** newTransports = new Transport * [transportCapacity];
    for (int i = 0; i < transportCount; ++i) {
        newTransports[i] = transports[i];
    }
    delete[] transports;
    transports = newTransports;
}

void Race::addTransport(Transport* transport) {
    if (transportCount == transportCapacity) {
        resizeTransportArray();
    }
    transports[transportCount++] = transport;
}

bool Race::canAddTransport(Transport* transport) const {
    if (groundRace && !transport->isGround()) return false;
    if (airRace && !transport->isAir()) return false;

    for (int i = 0; i < transportCount; ++i) {
        if (transports[i]->getName() == transport->getName()) {
            return false;
        }
    }
    return true;
}

Transport* Race::getTransport(int index) const {
    if (index < 0 || index >= transportCount) return nullptr;
    return transports[index];
}

int Race::getTransportCount() const {
    return transportCount;
}

double Race::getDistance() const {
    return distance;
}

bool Race::isGroundRace() const {
    return groundRace;
}

bool Race::isAirRace() const {
    return airRace;
}

void Race::runRace() const {
    struct Result {
        std::string name;
        double time;
    };

    Result* results = new Result[transportCount];

    for (int i = 0; i < transportCount; ++i) {
        results[i].name = transports[i]->getName();
        results[i].time = transports[i]->calculateTime(distance);
    }

    for (int i = 0; i < transportCount - 1; ++i) {
        for (int j = 0; j < transportCount - i - 1; ++j) {
            if (results[j].time > results[j + 1].time) {
                std::swap(results[j], results[j + 1]);
            }
        }
    }

    std::cout << "\nРезультаты гонки:\n";
    for (int i = 0; i < transportCount; ++i) {
        std::cout << i + 1 << ". " << results[i].name
            << ". Время: " << results[i].time << "\n";
    }

    delete[] results;
}