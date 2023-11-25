#include <cmath>
#include "point.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
//Setup
#define nums 100
Point points[nums];
void setup(){
    for(short i = 0; i < nums; i++){
        points[i].coords = {(double)i,(double)i};
    }
}

void iterate(){
    for(short i = 0; i < nums; i++){
        for(short j = 0; j < nums; j++){
            if(j==i){
                continue;
            }
            points[i].attract(points[j]);
        }
    }
    for(short i = 0; i < nums; i++){
        points[i].move();
    }
}
int main(){
    setup();
    std::cout << ((points[0].checkColl(points[1]))?"True":"False") << std::endl;
}