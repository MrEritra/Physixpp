#include "defines.hpp"
#include <iostream>
#include "draw.hpp"
#include "point.hpp"
#define WINDOWHEIGHT 1000
#define WINDOWWIDTH 1200
int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "My window");
    // run the program as long as the window is open
    std::vector<Point> points(10);
    for (uint32_t i = 0; i < points.size(); i++) {
        points[i].mass = (rand() % 60 + 0.1) / points.size();
        points[i].radius = rand() % 60 + 1;
        double x = rand() % WINDOWWIDTH;
        double y = rand() % WINDOWHEIGHT;
        std::cout << x << "\n";
        points[i].position = { x, y};
        double vx = (rand() % 100);
        double vy = (rand() % 100);
        points[i].velocity = {vx/ 100 / 8,vy/ 100 / 8};
            
    }
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
        //pos.x += 0.1;
        //pos.y += 0.1;
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