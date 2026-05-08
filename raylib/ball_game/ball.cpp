#include "ball.h"
#include "raylib.h"
#include <string>
#include <iostream>

using namespace std;

Ball::Ball(Vector2 pos, float rad, Color col, Vector2 spd){
    position = pos;
    r = rad;
    this->col = col;
    vel = spd;
}

void Ball::update(float dt){
    position.x += vel.x * dt;
    position.y += vel.y * dt;
    if(position.x <= 0 || position.x >= 800 - r)
        vel.x *= -1;

    if(position.y <= 0 || position.y >= 600 - r)
        vel.y *= -1;

}

void Ball::Draw(){
    DrawCircleV(position,r,col);
}


