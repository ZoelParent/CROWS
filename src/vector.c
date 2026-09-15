#include "vector.h"
#include <math.h>

double getMagnitude (Vector v) {
    return sqrt(pow(v.x_comp, 2) + pow(v.y_comp, 2));
}
