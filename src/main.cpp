#include "defines.h"
#include <iostream>
#include "draw.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.clear();
        // check all the window's events that were triggered since the last iteration of the loop
        Vec2 pos = {0,0};
        draw(pos,0,&window);
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