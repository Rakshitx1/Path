// plane.h

#ifndef PLANE_H
#define PLANE_H

class Point {
public:
    double x;
    double y;

    Point() : x(NAN), y(NAN) {}
    Point(double x, double y) : x(x), y(y) {}
};

#endif // PLANE_H