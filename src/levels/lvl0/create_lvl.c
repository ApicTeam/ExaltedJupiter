#include "game.h"
#include "minilib.h"

void Level1Loop()
{
    /* Base Variables */
    SDL_Window *window = CreateWindow();
    SDL_Renderer *renderer = CreateRenderer(window);

    SDL_Event event;
    bool quit = false;

    /* Textures */
    SDL_Texture *HeroRun = LoadTexture("../resource/characters/main_hero/hero_run_01.png", renderer);
    SDL_Texture *HeroIdle = LoadTexture("../resource/characters/main_hero/hero_run_01.png", renderer);

    /* Make Rectangles */

    //'windowRect' defines the dimensions of the rendering sprite on window
    SDL_Rect windowRect = {.x = 0,.y = 0, .w = 0, .h = 0};

    //'textureRect' defines the dimensions of the rendering sprite on texture
    SDL_Rect textureRect = {.x = 0, .y = 0, .w = 0, .h = 0};
//    SDL_QueryTexture(HeroRun, NULL, NULL, &textureRect.w, &textureRect.h);

//    SDL_Rect windowRect;
//    SDL_Rect textureRect;

//    textureRect.w /= 6;
    int totalFrames = 6;
    int delayPerFrame = 157.835782842584534950903505000099999990999090905949;
    int anim = false;

    SDL_Texture *CurrentHeroT;
    t_animation CurrentHeroA =
    {
        .windowsRect = &windowRect, .textureRect = &textureRect,
        .renderer = renderer, .filepath = "../resource/characters/main_hero/idle/hero_idle.png",
        .delayPerFrame = 100, .totalFrames = 3
    };

    while (!quit)
    {

//        int frame = (SDL_GetTicks() / delayPerFrame) % totalFrames;
        anim = false;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) quit = true;

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    CurrentHeroA.filepath = "../resource/characters/main_hero/run/hero_run.png";
                    CurrentHeroA.totalFrames = 6;
                    CurrentHeroA.delayPerFrame = 100;
                    windowRect.x += 10;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_A)
                {
                    CurrentHeroA.filepath = "../resource/characters/main_hero/run/hero_run.png";
                    CurrentHeroA.totalFrames = 6;
                    CurrentHeroA.delayPerFrame = 100;
                    windowRect.x -= 10;
                }
            }
            else if (event.type == SDL_KEYUP)
            {
                if (event.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    CurrentHeroA.filepath = "../resource/characters/main_hero/idle/hero_idle.png";
                    CurrentHeroA.totalFrames = 3;
                    CurrentHeroA.delayPerFrame = 100;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_A)
                {
                    CurrentHeroA.filepath = "../resource/characters/main_hero/idle/hero_idle.png";
                    CurrentHeroA.totalFrames = 3;
                    CurrentHeroA.delayPerFrame = 100;
                }
            }
        }

        CurrentHeroT = Animation(&CurrentHeroA);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //Copying the texture on to the window using
        //renderer, texture rectangle and window rectangle
        SDL_RenderCopy(renderer, CurrentHeroT, &textureRect, &windowRect);

        SDL_Delay(1000/21);
        SDL_RenderPresent(renderer);

    }
}