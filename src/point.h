#ifndef POINT_H_
#define POINT_H_

typedef struct Point {
    int x;
    int y;
} Point;

double calcPointDistance(Point x, Point y);

#endif // POINT_H_
