#include <cmath>
#include "point.h"
#include <vector>
typedef struct{
    double x;
    double y;
} vector2;
#define G .00000000001
int dist(std::vector<double> coord1, std::vector<double> coord2){
    double x1 = coord1[0];
    double y1 = coord1[1];
    double x2 = coord2[0];
    double y2 = coord2[1];
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
char Point::checkColl(const Point& otherPoint){
    return dist(this->coords,otherPoint.coords)<this->radius+otherPoint.radius;//this->x,otherPoint.x,this->y,otherPoint.y
}
Point::Point(int mass, double radius, std::vector<double> coords) {
    this->radius = radius;
    this->mass = mass;
    this->coords = coords;
}
Point::Point() {
    this->radius = 1;
    this->mass = 1;
    this->coords = {1,1};
}
char Point::attract(Point& otherPoint) {
    double r = dist(coords,otherPoint.coords);
    double a = G*otherPoint.mass/(r*r);
    double ax = a/(coords[0]-otherPoint.coords[0]);
    double ay = a/(coords[1]-otherPoint.coords[1]);
    vel[0]+=ax;
    vel[1]+=ay;
    return 0;
}
char Point::move(){
    coords[0]+=vel[0];
    coords[1]+=vel[1];
    return 0;
}
char Point::collideForce(Point& otherPoint){
    if(this->checkColl(otherPoint)){
        this->radius = sqrt(this->radius*this->radius+otherPoint.radius*otherPoint.radius);
        this->mass+=otherPoint.mass;2
        delete &otherPoint;
    }
    return 0;
}