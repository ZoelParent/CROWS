#include "aimbot.h"
#include <math.h>
#include <stdio.h>

#define PI 3.14

double calcHeading(Vehicle acv, Vehicle zbd) {
    double dX = 0;
    double dY = 0;

    double heading = 0;

    printf("---------------\n");
    printf("dX = %f\n", dX);
    printf("dY = %f\n", dY);
    printf("heading = %f\n", heading * 180/PI);

    return heading;
}
