#include "raylib.h"
#include "ball.h"

using namespace std;

class Game{
    public:
    Ball ball;
    Game();
    void update(float dt);
    void Draw();
};

