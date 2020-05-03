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

    SDL_Window *window = CreateWindow();
    SDL_Renderer *renderer = CreateRenderer(window);

    SDL_Texture *background = LoadTexture("../resource/tiles/tile_01.png", renderer);
    SDL_Texture *logo = LoadTexture("../resource/logo/logo_anim_0.bmp", renderer);

    SDL_Texture *hero = LoadTexture("../resource/characters/main_hero/hero_run.png", renderer);

    SDL_Rect Hero;

    SDL_Event event;
    int quit = false;

    int x_pos = (SCREEN_WIDTH - 100) / 2,  y_pos = (SCREEN_HEIGHT - 100) / 2;
    int x_vel = 0, y_vel = 0;

    int up = 0, down = 0, left = 0, right = 0;
    while (!quit)
    {

        int ticks = SDL_GetTicks();
        int sprite = (ticks / 100) % 4;

        SDL_Rect srcrect;
        SDL_Rect dstrect;


        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;

                case SDL_KEYDOWN:

                    switch (event.key.keysym.sym)
                    {
                        case SDLK_w:
                            srcrect.x = sprite * 100;
                            srcrect.y = 0;
                            srcrect.w = 100;
                            srcrect.h = 100;
                            dstrect.x = 10;
                            dstrect.y = 10;
                            dstrect.w = 100;
                            dstrect.h = 100;
                            up = 1;
                            break;

                        case SDLK_s:
                            srcrect.x = sprite * 100;
                            srcrect.y = 0;
                            srcrect.w = 100;
                            srcrect.h = 100;
                            dstrect.x = 10;
                            dstrect.y = 10;
                            dstrect.w = 100;
                            dstrect.h = 100;
                            down = 1;
                            break;

                        case SDLK_a:
                            srcrect.x = sprite * 100;
                            srcrect.y = 0;
                            srcrect.w = 100;
                            srcrect.h = 100;
                            dstrect.x = 10;
                            dstrect.y = 10;
                            dstrect.w = 100;
                            dstrect.h = 100;
                            left = 1;
                            break;

                        case SDLK_d:
                            srcrect.x = sprite * 100;
                            srcrect.y = 0;
                            srcrect.w = 100;
                            srcrect.h = 100;
                            dstrect.x = 10;
                            dstrect.y = 10;
                            dstrect.w = 100;
                            dstrect.h = 100;
                            right = 1;
                            break;
                    }
                    break;

                case SDL_KEYUP:

                    switch (event.key.keysym.sym)
                    {
                        case SDLK_w:
                            up = 0;
                            break;

                        case SDLK_s:
                            down = 0;
                            break;

                        case SDLK_a:
                            left = 0;
                            break;

                        case SDLK_d:
                            right = 0;
                            break;
                    }
            }
        }


        if (up && !down) y_vel = -SPEED;
        if (down && !up) y_vel = SPEED;
        if (left && !right) x_vel = -SPEED;
        if (right && !left) x_vel = SPEED;


        x_pos += x_vel / 60;
        y_pos += y_vel / 60;

        if (x_pos <= 0) x_pos = 0;
        if (y_pos <= 0) y_pos = 0;
        if (x_pos >= SCREEN_WIDTH - 100) x_pos = SCREEN_WIDTH - 100;
        if (y_pos >= SCREEN_HEIGHT - 100) x_pos = SCREEN_HEIGHT - 100;

        dstrect.x = (int) x_pos;
        dstrect.y = (int) y_pos;

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, hero, &srcrect, &dstrect);
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