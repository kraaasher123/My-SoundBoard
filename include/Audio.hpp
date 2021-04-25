#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


class Audio{
public:
    Mix_Music* loadMusic(const char* p_filepath);
    void playMusic(Mix_Music* p_music);
    void stopMusic();
    Mix_Chunk*  loadChunk(const char* p_filepath);
    void playChunk(Mix_Chunk* p_music);
    
private:
    

};