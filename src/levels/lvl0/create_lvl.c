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
    SDL_Texture *HeroSS = LoadTexture("../resource/characters/main_hero/hero_run_01.png", renderer);

    /* Make Rectangles */

    //'windowRect' defines the dimensions of the rendering sprite on window
    SDL_Rect windowRect =
            {
                .x = 0,
                .y = 0,
                .w = 500,
                .h = 500
            };

    //'textureRect' defines the dimensions of the rendering sprite on texture
    SDL_Rect textureRect = {.x = 0, .y = 0};
    SDL_QueryTexture(HeroSS, NULL, NULL, &textureRect.w, &textureRect.h);

    textureRect.w /= 6;
    int totalFrames = 6;
    int delayPerFrame = 157.835782842584534950903505000099999990999090905949;

    while (!quit)
    {

        int frame = (SDL_GetTicks() / delayPerFrame) % totalFrames;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) quit = true;

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    textureRect.x = frame * textureRect.w;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //Copying the texture on to the window using
        //renderer, texture rectangle and window rectangle
        SDL_RenderCopy(renderer, HeroSS, &textureRect, &windowRect);

        SDL_RenderPresent(renderer);
    }
}