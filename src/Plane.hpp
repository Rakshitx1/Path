// plane.h

#pragma once

#include <cmath>

class Point {
public:
    double x;
    double y;

    Point() : x(std::nan("")), y(std::nan("")) {}
    Point(double x, double y) : x(x), y(y) {}
};

