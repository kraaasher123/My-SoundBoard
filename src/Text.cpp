#include "Text.hpp"

Text::Text(const char* p_text, TTF_Font* font, SDL_Color color){
text = TTF_RenderText_Solid(font, p_text, color);

}

SDL_Surface* Text::getText(){
    return text;
}