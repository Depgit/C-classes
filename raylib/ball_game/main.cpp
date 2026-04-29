#include <iostream>
#include <raylib.h>
#include "Game.h"

using namespace std;
// g++ main.cpp -o game $(pkg-config --cflags --libs raylib)
int main(){
    InitWindow(800,600,"Ball Game");
    Game game;
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        float dt = GetFrameTime();
            game.update(dt);
        BeginDrawing();
        ClearBackground(BLACK);
            game.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
