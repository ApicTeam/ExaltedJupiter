#include "game.h"

#include "minilib.h"

/**
 * TODO Main
 */


#define SCREEN_WIDTH (640)
#define SCREEN_HEIGHT (480)

#define TILE_SIZE (40)
#define SPEED (300)

int GameMain()
{
    InitializeSDL();

    SDL_Window *window     = CreateWindow();
    SDL_Renderer *renderer = CreateRenderer(window);

    SDL_Texture *background = LoadTexture("../resource/background/background_0.bmp", renderer);
    SDL_Texture *logo       = LoadTexture("../resource/logo/logo_anim_0.bmp", renderer);

    SDL_Event event;
    int quit               = false;
    int hero_frame_counter = 0;

    SDL_Texture *hero = RenderHero(hero_frame_counter, IDLE, renderer);

    while (!quit)
    {
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;

                case SDL_KEYDOWN:
                    HeroMove(event.key.keysym.scancode);
            }
        }

        SDL_RenderClear(renderer);
        RenderTextureByInput(background, renderer, 0, 0, 1600, 800);
        RenderTexture(logo, renderer, 0, 0);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
    }


    // TODO Make garabage collector
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(logo);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();


    return 0;
}