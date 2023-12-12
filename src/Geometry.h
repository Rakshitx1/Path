// geometry.h

#ifndef GEOMETRY_H
#define GEOMETRY_H

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
    Point AB = {(A.x + B.x) / 2, (A.y + B.y) / 2};
    double d3 = distance(AB, C.center);

    if(d1 > C.radius && d2 > C.radius && d3 < C.radius) {
    }
    else{
        return;
    }
    
    double dx = B.x - A.x;
    double dy = B.y - A.y;
    double dr = sqrt(dx * dx + dy * dy);
    double D = A.x * B.y - B.x * A.y;

    double discriminant = C.radius * C.radius * dr * dr - D * D;

    if (discriminant < 0) {
        // No intersection
        return;
    } 
    else {
        double sign_dy = (dy < 0) ? -1 : 1;

        // Calculate x coordinates of intersections
        double x1 = (D * dy - sign_dy * dx * sqrt(discriminant)) / (dr * dr);
        double x2 = (D * dy + sign_dy * dx * sqrt(discriminant)) / (dr * dr);

        double sign_dx = (dx < 0) ? -1 : 1;

        // Calculate y coordinates of intersections
        double y1 = (-D * dx - abs(dy) * sqrt(discriminant)) / (dr * dr);
        double y2 = (-D * dx + abs(dy) * sqrt(discriminant)) / (dr * dr);

        // Set intersection points based on the center of the crater
        intersection1 = Point(C.center.x + x1, C.center.y + y1);
        intersection2 = Point(C.center.x + x2, C.center.y + y2);
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
