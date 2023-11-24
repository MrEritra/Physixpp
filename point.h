class Point {
    public:
        int mass = 1;
        int radius = 1;
        int x = 0;
        int y = 0;
        int vx = 0;
        int vy = 0;
        Point(int mass, int radius, int x, int y);
        Point();
        char attract(Point& otherPoint);
        char move();
        char collideForce();
        char checkColl(const Point& otherPoint);
};