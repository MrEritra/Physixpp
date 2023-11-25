#include "defines.hpp"
#include "point.hpp"
int dist(Vec2 pos1, Vec2 pos2) {
    return sqrt((pos1.x-pos2.x)*(pos1.x-pos2.x)+(pos1.y-pos2.y)*(pos1.y-pos2.y));
}
bool Point::checkColl(const Point& otherPoint){
    return dist(position,otherPoint.position) < (radius + otherPoint.radius);
}
Point::Point(int mass, double radius, Vec2 position, Vec2 velocity) {
    this->radius = radius;
    this->mass = mass;
    this->position.x = position.x;
    this->position.y = position.y;
    this->velocity.x = velocity.x;
    this->velocity.y = velocity.y;
}

void Point::attract(const Point& otherPoint) {
    double r = dist(position,otherPoint.position);
    if (r == 0)
        return;
    double F = this->mass*otherPoint.mass/(r*r);
    double distx = abs(position.x - otherPoint.position.x);
    double disty = abs(position.y - otherPoint.position.y);
    if (distx == 0 || disty == 0) {
        return;
    }
    double ax = (F * (distx / (distx+disty)) ) / mass;
    double ay = (F * (disty / (distx+disty)) ) / mass;
    double signX = (position.x - otherPoint.position.x) / distx;
    double singY = (position.y - otherPoint.position.y) / disty;
    velocity.x-=ax * signX;
    velocity.y-=ay * singY;
}

void Point::move() {
    position.x += velocity.x;
    position.y += velocity.y;
}
void Point::yu_gi_oh_FusionCard(const Point& otherPoint) {
    
    position.x = position.x + ((otherPoint.position.x - position.x) * mass / (mass + otherPoint.mass));
    position.y = position.y + ((otherPoint.position.y - position.y) * mass / (mass + otherPoint.mass));
    velocity.x = (velocity.x * mass + otherPoint.velocity.x * otherPoint.mass) / (otherPoint.mass + mass);
    velocity.x = sqrt((velocity.x * velocity.x * mass + otherPoint.velocity.x * otherPoint.velocity.x * otherPoint.mass) / (otherPoint.mass + mass));
    velocity.y = sqrt((velocity.y * velocity.y * mass + otherPoint.velocity.y * otherPoint.velocity.y * otherPoint.mass) / (otherPoint.mass + mass));
    mass+=otherPoint.mass;

    this->radius = sqrt(this->radius*this->radius+otherPoint.radius*otherPoint.radius);
    
    
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../../../res/Sound.wav")) {
        std::cout << "DEBUG\n";
        return;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    //sound.play();
}

void Point::draw(sf::RenderWindow* window) {
    sf::CircleShape shape(radius);
    sf::Texture texture;
    std::string texturestring;
    switch (image)
    {
    case 0:
        texturestring = "../../../res/Catgirl_color.png";
        break;
    case 1:
        texturestring = "../../../res/Femboy_color.png";
        break;
    case 2:
        texturestring = "../../../res/Catgirl-Mondface_color.png";
        break;
    
    default:
        break;
    }
    if (!texture.loadFromFile(texturestring)) {
        if (mass > 0) {
            shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
        } else {
            shape.setFillColor(sf::Color(0x00, 0x00, 0xFF));
        }
        shape.setPosition(position.x-radius,position.y-radius);
        window->draw(shape);
        return;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    //sprite.setTextureRect(sf::IntRect(0,0,radius,radius));
    sprite.setScale(sf::Vector2f(radius/10,radius/10));


    sprite.setPosition(position.x-radius,position.y-radius);
    window->draw(sprite);
    
}