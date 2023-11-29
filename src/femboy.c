#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define count 5
#define screenHeight 1000
#define screenWidth 2000

typedef struct{
    float a;
    float b;
}vec2;

typedef enum{
    boy,
    cat,
    moon
} anime;

typedef struct{
    vec2 coords;
    vec2 vel;
    signed char mass;
    char radius;
    anime face;
}Point;


float dist(Point p1, Point p2){
    float dX = p1.coords.a-p2.coords.a;
    float dY = p1.coords.b-p2.coords.b;
    return sqrt(dX*dX+dY*dY);
}

char checkColl(Point p1, Point p2){
    return dist(p1,p2)<p1.radius+p2.radius;
}

void collide(Point* p1, Point p2,Sound music){
    //float fxges = p1.vel.a*p1.mass+p2.vel.a*p2.mass;
    //float gyges = p1.vel.b*p1.mass+p2.vel.b*p2.mass;
    if(checkColl((*p1),p2)){
        PlaySound(music);
        (*p1).vel.a += ((*p1).coords.a-p2.coords.a)/50;
        (*p1).vel.b += ((*p1).coords.b-p2.coords.b)/50;
    }
}

Point points[count];

void setup(){
    srand(111);
    for(short i = 0; i < count; i++){
        points[i] = (Point){
            (vec2){
                rand()%screenWidth,rand()%screenHeight
            },
            (vec2){
                0,0//(rand()%50-10)/10,(rand()%50-10)/10
            },
            10,
            (rand()%3)*15+50,
            i%3
        };
        printf("%f,%f\n",points[i].vel.a,points[i].vel.b);
    }
}
void attract(Point* p1, Point p2){
    double r = dist(*p1,p2);
    if (r == 0)
        return;
    double F = p2.mass/(r);
    double distx = abs((*p1).coords.a - p2.coords.a);
    double disty = abs((*p1).coords.b - p2.coords.b);
    if (distx == 0 || disty == 0) {
        return;
    }
    double ax = (F * (distx / (distx+disty)) );
    double ay = (F * (disty / (distx+disty)) );
    double signX = ((*p1).coords.a - p2.coords.a) / distx;
    double singY = ((*p1).coords.b - p2.coords.b) / disty;
    (*p1).vel.a-=ax * signX;
    (*p1).vel.b-=ay * singY;
}
void updateVel(Sound music){
    for(short i = 0; i < count; i++){
        for(short j = 0; j < count; j++){
            if(j!=i){
                attract(&points[i],points[j]);
                collide(&points[i],points[j],music);
            }
        }
    }
}
void updatePos(){
    for(short i = 0; i < count; i++){
        points[i].coords.a+=points[i].vel.a;
        points[i].coords.b+=points[i].vel.b;
    }
}

void draw(Texture2D planeTex,Texture2D planeTex2,Texture2D planeTex3){
    for(short i = 0; i < count; i++){
        switch(points[i].face){
            case 0:{
                DrawTextureEx(planeTex, (Vector2){points[i].coords.a-points[i].radius,points[i].coords.b-points[i].radius}, 0, points[i].radius*2/planeTex.height, WHITE);
                break;
            }
            case 1:{
                DrawTextureEx(planeTex2, (Vector2){points[i].coords.a-points[i].radius,points[i].coords.b-points[i].radius}, 0, points[i].radius*2/planeTex2.height, WHITE);
                break;
            }
            case 2:{
                DrawTextureEx(planeTex3, (Vector2){points[i].coords.a-points[i].radius,points[i].coords.b-points[i].radius}, 0, points[i].radius*2/planeTex3.height, WHITE);
                break;
            }
        }
        //DrawTexture(planeTex2, screenWidth/3 - planeTex2.width/2, screenHeight/2 - planeTex2.height/2 - 40, WHITE);
        //DrawTexture(planeTex3, screenWidth/3 - planeTex3.width/2, screenHeight/2 - planeTex3.height/2 - 40, WHITE);
    }
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    setup();
    InitWindow(screenWidth, screenHeight, "Physix");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    Image planet = LoadImage("Femboy_color2.png");     // Load image in CPU memory (RAM)
    ImageResize(&planet, 100, 100);
    Texture2D planeTex = LoadTextureFromImage(planet);      // Image converted to texture, uploaded to GPU memory (VRAM)
    Image planet2 = LoadImage("Catgirl_color2.png");     // Load image in CPU memory (RAM)
    ImageResize(&planet2, 100, 100);
    Texture2D planeTex2 = LoadTextureFromImage(planet2);      // Image converted to texture, uploaded to GPU memory (VRAM)
    Image planet3 = LoadImage("Catgirl-Mondface_color2.png");     // Load image in CPU memory (RAM)
    ImageResize(&planet3, 100, 100);
    Texture2D planeTex3 = LoadTextureFromImage(planet3);      // Image converted to texture, uploaded to GPU memory (VRAM)
    InitAudioDevice();              // Initialize audio device

    Sound music = LoadSound("uwucut2.mp3");

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        updateVel(music);
        updatePos();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            //UpdateMusicStream(music); 
            ClearBackground(BLACK);
            draw(planeTex,planeTex2,planeTex3);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
