#include <cmath>
#include "point.h"
int dist(int x1, int x2, int y1, int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
char Point::checkColl(const Point& otherPoint){
    return dist(this->x,otherPoint.x,this->y,otherPoint.y)<this->radius+otherPoint.radius;
}
Point::Point(int mass, int radius, int x, int y) {
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
    int r = dist(x,otherPoint.x,y,otherPoint.y);
    int F = this->mass*otherPoint.mass/(r*r);
    int ax = F/(x-otherPoint.x);
    int ay = F/(y-otherPoint.y);
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