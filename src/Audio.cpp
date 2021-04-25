#include "Audio.hpp"


Mix_Music* Audio::loadMusic(const char* p_filepath){
    Mix_Music* music = NULL;
    music = Mix_LoadMUS(p_filepath);

    if(music == NULL){
        std::cout << "Could not load music. Error: " << SDL_GetError() << std::endl;
    }

    return music;
}

void Audio::playMusic(Mix_Music* p_music){
    Mix_PlayMusic(p_music, 0);
}

void Audio::stopMusic(){
    Mix_PauseMusic();
}