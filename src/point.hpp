#include "defines.hpp"

struct Vec2 {
    double x,y;
};


class Point {
    public:   
        Point(int mass, double radius, double x, double y);
        Point();
        void attract(const Point& otherPoint);
        void move();
        void collideForce();
        bool checkColl(const Point& otherPoint);
        void draw(sf::RenderWindow* window);
    private:
        double mass = 1;
        double radius = 1;
        Vec2 position = {0,0};
        Vec2 velocity = {0,0};
};