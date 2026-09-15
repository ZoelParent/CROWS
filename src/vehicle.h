#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "point.h"

typedef enum VehicleType { ACV, ZBD } VehicleType;

typedef struct Vehicle {
    Point location;
    _Bool weaponActive;
    double weaponHeading;
    VehicleType type;
} Vehicle;

#endif // VEHICLE_H_
