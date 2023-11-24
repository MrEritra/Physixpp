class Point {
    public:
        double mass = 1;
        double radius = 1;
        double x = 0;
        double y = 0;
        double vx = 0;
        double vy = 0;
        Point(int mass, double radius, double x, double y);
        Point();
        char attract(Point& otherPoint);
        char move();
        char collideForce();
        char checkColl(const Point& otherPoint);
};