#include "defines.h"
#include <iostream>
#include "draw.h"
#define WINDOWHEIGHT 600
#define WINDOWWIDTH 800
int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "My window");
    Vec2 pos = {0,0};
    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.clear();
        // check all the window's events that were triggered since the last iteration of the loop
        
        draw(pos,50,&window);
        //pos.x += 0.1;
        //pos.y += 0.1;
        sf::Event event;
        window.display();
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}