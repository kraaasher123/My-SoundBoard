#include "RenderWindow.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_audio.h>


RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height){
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);
    
    if(window == NULL){
        std::cout << "Window has failed. Error: " << SDL_GetError() << std::endl;

    }


    renderer = SDL_CreateRenderer(window, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filepath){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filepath);

    if(texture == NULL){
        std::cout << "Could not load texture. Error: " << SDL_GetError() << std::endl;
    }


    return texture;

}



void RenderWindow::cleanUp(){
    SDL_DestroyWindow(window);
    
}

void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& entity){
    SDL_Rect src;
    src.x = entity.getCurrentFrame().x;
    src.y = entity.getCurrentFrame().y;
    src.w = entity.getCurrentFrame().w;
    src.h = entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = entity.getX();
    dst.y = entity.getY();
    dst.w = entity.getCurrentFrame().w;
    dst.h = entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, entity.getTex(), &src,    &dst);
}

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}

void RenderWindow::bgColor(int r, int g, int b, float a){
    SDL_SetRenderDrawColor(renderer, r , g , b ,a);
}

TTF_Font* RenderWindow::loadFont(const char* filepath, int font_size){
    TTF_Font* font = NULL;
    font = TTF_OpenFont(filepath, font_size);

    if(font == NULL){
        std::cout << "Could not load font. Error: " << SDL_GetError() << std::endl;
    }

    return font;
}


SDL_Texture* RenderWindow::surfaceToTexture(SDL_Surface* surface){
    SDL_Texture* texture;
    texture = SDL_CreateTextureFromSurface(renderer, surface);


    return texture;
}


void RenderWindow::renderText(Entity& entity){
int texW = 0;
int texH = 0;

SDL_QueryTexture(entity.getTex(), NULL, NULL, &texW, &texH);

SDL_Rect src;
src.x = entity.getCurrentFrame().x;
src.y = entity.getCurrentFrame().y;
src.w = texW;
src.h = texH;

SDL_Rect dst;
dst.x = entity.getX();
dst.y = entity.getY();
dst.w = texW;
dst.h = texH;

SDL_RenderCopy(renderer, entity.getTex(), &src, &dst);
}

SDL_Texture* RenderWindow::createText(const char* p_text, TTF_Font* font, SDL_Color color){
    SDL_Surface* text = TTF_RenderText_Solid(font, p_text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,text);

    if(texture == NULL){
        std::cout << "Could not create Text.Error: " <<  SDL_GetError() << std::endl;
    }

    
    return texture;
}