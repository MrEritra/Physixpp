#include "defines.hpp"
#include "point.hpp"
int dist(Vec2 pos1, Vec2 pos2) {
    return sqrt((pos1.x-pos2.x)*(pos1.x-pos2.x)+(pos1.y-pos2.y)*(pos1.y-pos2.y));
}
bool Point::checkColl(const Point& otherPoint){
    return dist(position,otherPoint.position) < (radius + otherPoint.radius);
}
Point::Point(int mass, double radius, double x, double y) {
    this->radius = radius;
    this->mass = mass;
    position.x = x;
    position.y = y;
}
Point::Point() {
    radius = 1;
    mass = 1;
    position.x = 1;
    position.y = 1;
}

void Point::attract(const Point& otherPoint) {
    double r = dist(position,otherPoint.position);
    double F = this->mass*otherPoint.mass/(r*r);
    double ax = F/(position.x-otherPoint.position.x);
    double ay = F/(position.y-otherPoint.position.y);
    velocity.x-=ax;
    velocity.y-=ay;
}

void Point::move() {
    position.x += velocity.x;
    position.y += velocity.y;
}
void Point::collideForce() {

}

void Point::draw(sf::RenderWindow* window) {
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    shape.setPosition(position.x-radius,position.y-radius);
    window->draw(shape);
}