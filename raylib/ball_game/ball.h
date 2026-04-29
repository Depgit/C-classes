#include "raylib.h"
#include <string>

using namespace std;

class Ball{
public:
    Vector2 position;// position.x, position.y
    float r;
    Color col;
    Vector2 vel;
    Ball(Vector2 pos, float rad, Color color, Vector2 spd);
    void update(float dt);
    void Draw();
};
