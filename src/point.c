#include "point.h"
#include <math.h>

double calcPointDistance(Point x, Point y) {
    int xDistance = x.x - y.x;
    int yDistance = x.y - y.y;

    return sqrt(pow(xDistance, 2) + pow(yDistance, 2));
}
