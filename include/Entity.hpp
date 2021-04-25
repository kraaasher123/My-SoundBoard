#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>



class Entity{
public:
    Entity(int p_x, int p_y, SDL_Texture* p_tex, Mix_Music* p_music);
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
    int getX();
    int getY();
    bool getDetected();
    void setDetected(bool p_detected);
    SDL_Rect getDRect();
    void setTextureColor(int r, int g, int b);
    void setCurrentFrame(int num, int index);
    Mix_Music* getMusic();

private:
    Mix_Music* music;
    SDL_Texture* texture;
    SDL_Rect currentFrame;
    SDL_Rect detectionRect;
    int x , y;
    bool detected = false;
    
};