#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Audio.hpp"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "Text.hpp"
#include "Utils.hpp"

bool detection(Entity &entity, int x, int y)
{
    return (x >= entity.getDRect().x && y >= entity.getDRect().y && x < entity.getDRect().x + entity.getDRect().w && y < entity.getDRect().y + entity.getDRect().h);
}

int main(int argc, char **)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has stopped working. Error" << SDL_GetError() << std::endl;

    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "IMG_Init has stopped working. Error" << SDL_GetError() << std::endl;

    if (SDL_Init(SDL_INIT_AUDIO) > 0)
        std::cout << "SDL_audio has stopped working. Error" << SDL_GetError() << std::endl;

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048))
        std::cout << "Mixer has stopped working. Error: " << SDL_GetError() << std::endl;

    if (TTF_Init() > 0)
        std::cout << "TTF_Init has stopped working. Error: " << TTF_GetError() << std::endl;

    RenderWindow window("Sean Soundboard v1.0", 854, 480);
    Audio audio;

    SDL_Texture *blue = window.loadTexture("res/gfx/sprite1.png");
    TTF_Font *font = window.loadFont("res/fonts/pixel.ttf", 25);
    SDL_Color color = {0, 0, 0};

    SDL_Texture* text1 = window.createText("Weird Flukemarm", font, color);
    SDL_Texture* text0 = window.createText("Radiance", font, color);
    SDL_Texture* text2 = window.createText("IDK Sound", font, color);
    std::vector<Mix_Music*> music = {audio.loadMusic("res/sfx/radiance.wav"), audio.loadMusic("res/sfx/sealedvessel.mp3"), audio.loadMusic("res/sfx/click.wav")};

    std::vector<Entity> entities = {Entity(60 + 100, 40, blue, music[0]), Entity(180 + 200, 40, blue, music[1]), Entity(300 + 300, 40, blue, music[2])};
    //Mix_Music* sealedvessel = audio.loadMusic("res/sfx/radiance.wav");
    std::vector<Entity> texts = {Entity(130, 104, text0, NULL),Entity(300, 104, text1, NULL),Entity(560, 104, text2, NULL)};

   

    int mouseX, mouseY;

    bool gameRunning = true;
    SDL_Event event;

    const float timeStep = 0.01f;
    float accumulator = 0.1f;
    float currentTime = utils::hireTimeInSeconds();

    while (gameRunning)
    {
        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    gameRunning = false;
                    break;
                case SDL_MOUSEMOTION:

                    SDL_GetMouseState(&mouseX, &mouseY);
                    break;
                }
                for (Entity &e : entities)
                {
                    if (e.getDetected() == true && event.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if (!Mix_PlayingMusic() || Mix_PausedMusic())
                        {
                            audio.playMusic(e.getMusic());
                        }
                        else if (Mix_PlayingMusic())
                        {
                            audio.stopMusic();
                        }
                    }
                }
            }

            accumulator -= timeStep;
        }
        window.clear();

        for (Entity &e : entities)
        {
            window.render(e);
            for (Entity &t : texts)
            {
                window.renderText(t);
            }
        }

        window.display();
        window.bgColor(200, 200, 200, 200.5f);

        for (Entity &e : entities)
        {
            if (detection(e, mouseX, mouseY))
            {
                e.setDetected(true);
            }
            else if (!detection(e, mouseX, mouseY))
            {
                e.setDetected(false);
            }
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
    window.cleanUp();

    return 0;
}