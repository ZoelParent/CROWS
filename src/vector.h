#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct Vector {
    double x_comp;
    double y_comp;
} Vector;

double getMagnitude (Vector v);

#endif // VECTOR_H_
