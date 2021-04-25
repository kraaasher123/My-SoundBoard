#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_audio.h>
#include "Entity.hpp"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>



class RenderWindow{
public:
    RenderWindow(const char* p_title, int p_width, int p_height);
    SDL_Texture* loadTexture(const char* p_filepath);
    void cleanUp();
    void clear();
    void render(Entity& entity);
    void display();
    void bgColor(int r, int g, int b, float a);
    TTF_Font* loadFont(const char* filepath, int font_size);
    SDL_Texture* surfaceToTexture(SDL_Surface* surface);
    void renderText(Entity& entity);
    SDL_Texture* createText(const char* p_text, TTF_Font* font, SDL_Color color);
    



private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    
};