#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() : ball({400,300},10,RED,{300,300}), paddle({400,550,50,10},{300,0},YELLOW){

}

void Game::update(float dt){
    if(((ball.position.x >= paddle.rec.x) && (ball.position.x <= paddle.rec.x + paddle.rec.width)) && ((ball.position.y <= ((paddle.rec.y + paddle.rec.height)+ball.r) && (ball.position.y >= ((paddle.rec.y + paddle.rec.height)- ball.r))))){
        ball.vel.y *= -1;
    }
    ball.update(dt);
    paddle.Update(dt);
}

void Game::Draw(){
    ball.Draw();
    paddle.Draw();
}
