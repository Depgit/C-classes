#include <iostream>
#include "Paddle.h"
#include "raylib.h"

Paddle::Paddle(Rectangle rec, Vector2 vel, Color col ){
    this->rec = rec;
    this->vel = vel;
    this->col = col;
}

void Paddle::Update(float dt){
    if(IsKeyDown(KEY_LEFT)) rec.x -= vel.x * dt;

    if(IsKeyDown(KEY_RIGHT))rec.x += vel.x * dt;

    if(rec.x <= 0 ){
        rec.x = 0;
    }
    if(rec.x >= 800 - rec.width){
        rec.x = 800 - rec.width;
    }




}

void Paddle::Draw(){
    DrawRectangleRec(rec,col);
}
