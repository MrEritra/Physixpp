#include <vector>
class Point {
    public:
        double mass = 1;
        double radius = 1;
        std::vector<double> coords = {1,1};
        std::vector<double> vel = {0,0};
        Point(int mass, double radius, std::vector<double> coords);
        Point();
        char attract(Point& otherPoint);
        char move();
        char collideForce();
        char checkColl(const Point& otherPoint);
};