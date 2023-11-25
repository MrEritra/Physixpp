#include "defines.hpp"
#include <iostream>
#include "draw.hpp"
#include "point.hpp"
#define WINDOWHEIGHT 1000
#define WINDOWWIDTH 1200
int main(int argc, char* argv[]) {
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "My window");
    // run the program as long as the window is open
    srand (time(NULL));
    std::vector<Point> points(50);
    for (uint32_t i = 0; i < points.size(); i++) {
        if (argc == 2) {
            double sign = (rand() % 2 -0.5) * 2;
            points[i].mass = (rand() % 30 + 0.1) / points.size() * sign;
        } else {
            points[i].mass = (rand() % 30 + 0.1) / points.size();
        }
        
        points[i].radius = rand() % 60 + 1;
        double x = rand() % WINDOWWIDTH;
        double y = rand() % WINDOWHEIGHT;
        //std::cout << x << "\n";
        points[i].position = { x, y};
        double vx = (rand() % 100);
        double vy = (rand() % 100);
        //points[i].velocity = {vx/ 100 / 8,vy/ 100 / 8};
            
    }
    //window.setFramerateLimit(60);
    while (window.isOpen()) {
        window.clear();
        // check all the window's events that were triggered since the last iteration of the loop
        for (uint32_t i = 0; i < points.size(); i++) {
            points[i].draw(&window);
        }
        for (uint32_t i = 0; i < points.size(); i++) {
            points[i].move();
        }
        for (uint32_t i0 = 0; i0 < points.size(); i0++) {
            for (uint32_t i1 = 0; i1 < points.size(); i1++) {
                if (i0 == i1)
                    break;
                points[i0].attract(points[i1]);
            }
        }
        for (uint32_t i0 = 0; i0 < points.size(); i0++) {
            for (uint32_t i1 = 0; i1 < points.size(); i1++) {
                if (i0 == i1)
                    break;
                if (points[i0].checkColl(points[i1])) {
                    points[i0].yu_gi_oh_FusionCard(points[i1]);
                    points[i1] = points[points.size()-1];
                    points.pop_back();
                }
                if (i0 >= points.size()) 
                    break;
            }
            
        }
        //std::cout << points[10].position.x << " : " << points[10].position.y << "\n";
        sf::Event event;
        window.display();
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}