#include "TransportFactory.h"
#include "Camel.h"
#include "FastCamel.h"
#include "Centaur.h"
#include "AllTerrainBoots.h"
#include "CarpetPlane.h"
#include "Eagle.h"
#include "Broom.h"

Transport* TransportFactory::createTransport(int type) {
    switch (type) {
    case 1: return new AllTerrainBoots();
    case 2: return new Broom();
    case 3: return new Camel();
    case 4: return new Centaur();
    case 5: return new Eagle();
    case 6: return new FastCamel();
    case 7: return new CarpetPlane();
    default: return nullptr;
    }
}