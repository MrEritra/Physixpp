#include "draw.h"

void draw(Vec2 position, double radius, sf::RenderWindow* window) {
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window->draw(shape);
}