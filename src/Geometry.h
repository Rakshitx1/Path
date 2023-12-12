// geometry.h

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#include "Plane.h"
#include "Crater.h"

void PointSwitch(Point &A, Point &B) {
    A.x = A.x + B.x;
    B.x = A.x - B.x;
    A.x = A.x - B.x;
    A.y = A.y + B.y;
    B.y = A.y - B.y;
    A.y = A.y - B.y;
}

double dotProduct(Point A, Point B) {
    return A.x * B.x + A.y * B.y;
}

double magnitude(Point A) {
    return pow(pow(A.x, 2) + pow(A.y, 2), 0.5);
}

double distance(Point A, Point B) {
    return pow(pow(A.x - B.x, 2) + pow(A.y - B.y, 2), 0.5);
}

void findIntersections(Point A, Point B, Crater C, Point& intersection1, Point& intersection2) {
    double d1 = distance(A, C.center);
    double d2 = distance(B, C.center);
    double d3 = 0;
    if(d1 <= C.radius || d2 <= C.radius || d3 > C.radius){
        return;
    }
    double dx = B.x - A.x;
    double dy = B.y - A.y;
    if(dy > 0 && dx == 0){
        double a = 1;
        double b = -2*C.center.y;
        double c = pow(C.center.x - dy,2) + pow(C.center.y, 2) - pow(C.radius, 2);
        double discriminant = pow(b, 2) - 4 * a * c;
        if(discriminant <= 0){
            return;
        }
        double y1 = (-b + pow(discriminant, 0.5)) / (2 * a);
        double y2 = (-b - pow(discriminant, 0.5)) / (2 * a);
        intersection1 = {A.x, y1};
        intersection2 = {A.x, y2};
        
    }
    else{
        double m = dy / dx;
        double c = A.y - m * A.x;
        double a = 1 + pow(m, 2);
        double b = -2 * C.center.x + 2 * m * (c - C.center.y);
        double c1 = pow(C.center.x, 2) + pow(c - C.center.y, 2) - pow(C.radius, 2);
        double discriminant = pow(b, 2) - 4 * a * c1;
        if (discriminant <= 0) {
            return;
        }
        double x1 = (-b + pow(discriminant, 0.5)) / (2 * a);
        double x2 = (-b - pow(discriminant, 0.5)) / (2 * a);
        double y1 = m * x1 + c;
        double y2 = m * x2 + c;
        intersection1 = {x1, y1};
        intersection2 = {x2, y2};
    }

    if(distance(intersection1, A) > distance(intersection2, A)){
        PointSwitch(intersection1, intersection2);
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
