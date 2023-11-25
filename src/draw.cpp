#include "draw.h"

void draw(Vec2 position, double radius, sf::RenderWindow* window) {
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    shape.setPosition(position.x-radius,position.y-radius);
    window->draw(shape);
}