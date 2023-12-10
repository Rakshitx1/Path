// geometry.h

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <limits>
#include <cmath>
#include "Plane.h"
#include "Crater.h"

double dotProduct(Point A, Point B) {
    return A.x * B.x + A.y * B.y;
}

double magnitude(Point A) {
    return sqrt(A.x * A.x + A.y * A.y);
}

double distance(Point A, Point B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

void findIntersections(Point A, Point B, Crater C, Point& intersection1, Point& intersection2) {
    double d1 = distance(A, C.center);
    double d2 = distance(B, C.center);
    if(d1 < C.radius && d2 < C.radius) {
        intersection1 = intersection2 = Point(std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN());
        return;
    }
    double d3 = abs((B.x - A.x) * (A.y - C.center.y) - (A.x - C.center.x) * (B.y - A.y)) / sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    if(d3 > C.radius) {
        intersection1 = intersection2 = Point(std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN());
        return;
    }

    
}

double angleBetweenVectors(Point A, Point B, Point C) {
    Point AB = {B.x - A.x, B.y - A.y};
    Point BC = {C.x - B.x, C.y - B.y};

    double dot = dotProduct(AB, BC);
    double magAB = magnitude(AB);
    double magBC = magnitude(BC);

    return M_PI - acos(dot / (magAB * magBC));
}

#endif // GEOMETRY_H
