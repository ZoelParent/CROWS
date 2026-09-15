#include "aimbot.h"
#include <math.h>

double calcHeading (Vehicle acv, Vehicle zbd) {
    int xDelta = zbd.location.x - acv.location.x;
    int yDelta = zbd.location.y - acv.location.y;

    return atan( (double) yDelta / xDelta);
}
