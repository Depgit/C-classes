#include "Game.h"
#include "raylib.h"

Game::Game() : ball({400,300},10,RED,{10,12}){

}

void Game::update(float dt){
    ball.update(dt);
}

void Game::Draw(){
    ball.Draw();
}

