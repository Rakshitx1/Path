#include <iostream>
#include <cmath>
#include <limits>
#include "Geometry.h"

using namespace std;

// Function to calculate the cost between two Points
double calculateCost(const Point& a, const Point& b) {
    return distance(a, b);
}

// Function to find the shortest path avoiding the Crater
double findShortestPath(const Point& A, const Point& B, const Crater& c) {
    Point intersection1, intersection2;

    // Find intersection Points
    findIntersections(A, B, c, intersection1, intersection2);

    if(isnan(intersection1.x) || isnan(intersection1.y) || isnan(intersection2.x) || isnan(intersection2.y)) {
        return calculateCost(A, B);
    }

    // Calculate distances
    double distanceStartToIntersect1 = calculateCost(A, intersection1);
    double distanceIntersect2ToEnd = calculateCost(intersection2, B);

    // Calculate the angle between the two intersection Points and the center of the Crater
    double angle = angleBetweenVectors(intersection1, c.center, intersection2);
    cout << angle << endl;
    if (angle < 0)
    {
        angle = 2 * M_PI + angle;
    }
    if(angle > M_PI) {
        angle = 2 * M_PI - angle;
    }
    
    // Calculate the additional cost due to the circular path
    double circularPathCost = c.radius * angle;

    cout << intersection1.x << " " << intersection1.y << endl;
    cout << intersection2.x << " " << intersection2.y << endl;

    cout << distanceStartToIntersect1 << " " << circularPathCost << " " << distanceIntersect2ToEnd << endl;

    // Calculate total cost
    double totalCost = distanceStartToIntersect1 + circularPathCost + distanceIntersect2ToEnd;

    return totalCost;
}

int main() {
    Point A(3, 0);
    Point B(0, 4);
    Crater C(Point(0, 0), 10);

    Point intersection1, intersection2;
    findIntersections(A, B, C, intersection1, intersection2);

    double shortestPathCost = findShortestPath(A, B, C);

    cout << "Shortest path cost: " << shortestPathCost << endl;

    return 0;
}