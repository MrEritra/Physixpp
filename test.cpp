#include <cmath>
#include "point.h"
#include <iostream>
int main(){
    Point* p1 = new Point(1,2,1,1);
    Point* p2 = new Point(1,3,4,1);
    Point points[2];
    std::cout << ((p1->checkColl(*p2))?"True":"False") << std::endl;
}