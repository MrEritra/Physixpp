#include <cmath>
#include "point.h"
#include <vector>
int dist(std::vector<double> coord1, std::vector<double> coord2){
    double x1 = coord1[0];
    double y1 = coord1[1];
    double x2 = coord2[0];
    double y2 = coord2[1];
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
char Point::checkColl(const Point& otherPoint){
    return dist({this->x,this->y},{otherPoint.x,otherPoint.y})<this->radius+otherPoint.radius;//this->x,otherPoint.x,this->y,otherPoint.y
}
Point::Point(int mass, double radius, double x, double y) {
    this->radius = radius;
    this->mass = mass;
    this->x = x;
    this->y = y;
}
Point::Point() {
    this->radius = 1;
    this->mass = 1;
    this->x = 1;
    this->y = 1;
}
char Point::attract(Point& otherPoint) {
    double r = dist({x,y},{otherPoint.x,otherPoint.y});
    double F = this->mass*otherPoint.mass/(r*r);
    double ax = F/(x-otherPoint.x);
    double ay = F/(y-otherPoint.y);
    vx+=ax;
    vy+=ay;
    return 0;
}
char Point::move(){
    x+=vx;
    y+=vy;
    return 0;
}
char Point::collideForce(){
    return 0;
}