// crater.h

#pragma once

#include "Plane.hpp"


class Crater {
public:
    Point center;
    double radius;

    Crater(const Point& center, double radius) : center(center), radius(radius) {}

    bool isPointInside(const Point& point) const {
        double distance_squared = (point.x - center.x) * (point.x - center.x) + (point.y - center.y) * (point.y - center.y);
        return distance_squared <= radius * radius;
    }
};
