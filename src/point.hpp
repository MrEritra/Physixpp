#include "defines.hpp"

struct Vec2 {
    double x,y;
};


class Point {
    public:   
        Point(int mass = 1, double radius = 10, Vec2 position = {0,0}, Vec2 velocity = {0,0});
        void attract(const Point& otherPoint);
        void move();
        void yu_gi_oh_FusionCard(const Point& otherPoint);
        bool checkColl(const Point& otherPoint);
        void draw(sf::RenderWindow* window);
        double mass = 1;
        double radius = 1;
        Vec2 position = {0,0};
        Vec2 velocity = {0,0};
        uint32_t image = 0;
    private:

        
};