#include <iostream>
#include <raylib.h>

using namespace std;
// g++ main.cpp -o game $(pkg-config --cflags --libs raylib)
int main(){
    //void InitWindow(int width, int height, const char *title);  // Initialize window and OpenGL context
    float x,y,var_x,var_y;
    int screeHeight, screenWidth;
    float speed;
    screeHeight = 600;
    screenWidth = 800;
    x = screeHeight / 2; y = screenWidth / 2; var_x = 1; var_y = 1; speed = 0.1;
    InitWindow(screenWidth, screeHeight,"Ball Game");
    // WindowShouldClose
    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);
        //void DrawCircle(int centerX, int centerY, float radius, Color color);
        DrawCircle(x,y,10,GREEN);
        x += var_x * speed;
        y += var_y * speed;
        if(x >= screenWidth - 10 || x <= 10) var_x *= -1;
        if(y >= screeHeight - 10 || y <= 10) var_y *= -1;
        // DrawText(x,y,20,WHITE);
        DrawText("X and y",0,0,20,WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}