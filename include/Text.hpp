#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


class Text{
public:
Text(const char* p_text, TTF_Font* font, SDL_Color color);
SDL_Surface* getText();

private:
SDL_Surface* text;
};