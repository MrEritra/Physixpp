#include "defines.hpp"
#include <iostream>
#include "draw.hpp"
#include "point.hpp"
#define WINDOWHEIGHT 600
#define WINDOWWIDTH 800
int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "My window");
    // run the program as long as the window is open
    Point a = Point(10,30,{0,0}, {0,0.05});
    Point b = Point(20,60,{600,600},{0,-0.05});
    while (window.isOpen()) {
        window.clear();
        // check all the window's events that were triggered since the last iteration of the loop
        
        a.draw(&window);
        b.draw(&window);
        a.move();
        b.move();
        a.attract(b);
        b.attract(a);
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