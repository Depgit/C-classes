#include "raylib.h"
#include <string>

using namespace std;

class Paddle{
public:
    Rectangle rec;
    Vector2 vel;
    Color col;

    Paddle(Rectangle rec, Vector2 vel, Color col);
    void Update(float dt);
    void Draw();
};
