#pragma once
#include "Transport.h"

class TransportFactory {
public:
    static Transport* createTransport(int type);
};