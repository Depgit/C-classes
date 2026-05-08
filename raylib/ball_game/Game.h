#include "raylib.h"
#include "ball.h"
#include "Paddle.h"

using namespace std;

class Game{
    public:
    Ball ball;
    Paddle paddle;
    Game();
    void update(float dt);
    void Draw();
};

