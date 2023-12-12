#include <iostream>
#include <cmath>
#include <limits>
#include "Geometry.h"

using namespace std;

// Function to find the shortest path avoiding the Crater
double findShortestPath(const Point& A, const Point& B, const Crater& c) {
    Point intersection1, intersection2;

    // Find intersection Points
    findIntersections(A, B, c, intersection1, intersection2);

    if(isnan(intersection1.x) || isnan(intersection1.y) || isnan(intersection2.x) || isnan(intersection2.y)) {
        cerr << "No Intersection" << endl;
        return distance(A, B);
    }

    // Calculate distances
    double distanceStartToIntersect1 = distance(A, intersection1);
    double distanceIntersect2ToEnd = distance(intersection2, B);

    // Calculate the angle between the two intersection Points and the center of the Crater
    double angle = angleBetweenVectors(intersection1, c.center, intersection2);
    
    // Calculate the additional cost due to the circular path
    double circularPathCost = c.radius * angle;

    cout << angle << endl;
    cout << intersection1.x << " " << intersection1.y << endl;
    cout << intersection2.x << " " << intersection2.y << endl;

    cout << distanceStartToIntersect1 << " " << circularPathCost << " " << distanceIntersect2ToEnd << endl;

    // Calculate total cost
    double totalCost = distanceStartToIntersect1 + circularPathCost + distanceIntersect2ToEnd;

    return totalCost;
}

int main() {
    Point A(0, 0);
    Point B(10, 0);
    Crater C(Point(1, 5), 4);

    double shortestPathCost = findShortestPath(A, B, C);

    cout << "Shortest path cost: " << shortestPathCost << endl;

    return 0;
}