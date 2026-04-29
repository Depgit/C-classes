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
    std::cout <<"Inside ball "  << std::endl;
    position.x += vel.x * dt;
    position.y += vel.y * dt;
    std::cout <<position.x<< " "<<position.y  << std::endl;
    if(position.x <= 0 || position.x >= 800 - r)
        vel.x *= -1;

    if(position.y <= 0 || position.y >= 600 - r)
        vel.y *= -1;
}


void Ball::Draw(){
    DrawCircleV(position,r,col);
}


