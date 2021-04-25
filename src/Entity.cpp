#include "Entity.hpp"
#include <iostream>


Entity::Entity(int p_x, int p_y, SDL_Texture* p_tex, Mix_Music* p_music)

{
    x = p_x;
    y = p_y;
    texture = p_tex;
    music = p_music;

    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 64;
    currentFrame.h = 64;

    detectionRect.x = x;
    detectionRect.y = y;
    detectionRect.w = currentFrame.w;
    detectionRect.h = currentFrame.h;

}


SDL_Texture* Entity::getTex(){

    return texture;
}

SDL_Rect Entity::getCurrentFrame(){
    return currentFrame;
}

int Entity::getX(){
    return x;
}

int Entity::getY(){
    return y;
}

bool Entity::getDetected(){
    return detected;
}

void Entity::setDetected(bool p_detected){
    this->detected = p_detected;
}

SDL_Rect Entity::getDRect(){
    return detectionRect;
}

void Entity::setTextureColor(int r, int g, int b){
    
    SDL_SetTextureColorMod(this->getTex(), r ,g ,b);
}

void Entity::setCurrentFrame(int num, int index){
    if(index == 1){
        this->currentFrame.x = num;
    }else if(index == 2){
        this->currentFrame.y = num;
    }else if(index == 3){
        this->currentFrame.w = num;
    }else if(index == 4){
        this->currentFrame.h = num;
    }   
    

}

Mix_Music* Entity::getMusic(){
    return music;
}