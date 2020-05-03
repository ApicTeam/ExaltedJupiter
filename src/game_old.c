#include "game.h"
#include "minilib.h"

/**
 * TODO Main
 * TODO Add error_handler
 */

void InitializeSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        exit(1);
    }
}

SDL_Window *CreateWindow()
{

    /*
     * TODO Pass arguments to function window size (Width, Height) and arguments borderless or fullscreen
     * TODO Create start menu like in unity
     */

    SDL_Window *window = SDL_CreateWindow("Exalted Jupiter", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1600,
                                          800, SDL_WINDOW_BORDERLESS);

    if (!window)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        exit(1);
    }

    return window;
}

SDL_Renderer *CreateRenderer(SDL_Window *window)
{
    /*
     * Hints:
     * -1 to initialize the first one supporting the requested flags
     */
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
    {
        fprintf(stderr, "SDL_CreateRender Error: %s\n", SDL_GetError());
        exit(1);
    }
}
// TODO start
//  make from to function one
SDL_Surface *CreateSurfaceBMP(char *filepath)
{
    SDL_Surface *surface = SDL_LoadBMP(filepath);

    if (!surface)
    {
        fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
        exit(1);
    }

    return surface;
}

SDL_Texture *CreateTexture(SDL_Renderer *renderer, SDL_Surface *surface)
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        exit(1);
    }

    return texture;
}
// TODO End

SDL_Texture *LoadImage(char *filepath, SDL_Renderer *renderer)
{
    /* Variable Definitions */
    SDL_Surface *surface = SDL_LoadBMP(filepath);
    SDL_Texture *texture = NULL;

    if (!surface)
    {
        fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
        exit(1);
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        exit(1);
    }

    return texture;
}

void DrawSurface(int x, int y, int w, int h, SDL_Texture *texture, SDL_Renderer *renderer)
{
    SDL_Rect position;

    position.x = x;
    position.y = y;
    position.w = w;
    position.h = h;

//    SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(renderer, texture, NULL, &position);
}


int GameMain()
{

    InitializeSDL();

    SDL_Window *window     = CreateWindow();
    SDL_Renderer *renderer = CreateRenderer(window);

    SDL_Texture *background = NULL, *logo = NULL;

    background = LoadImage("../resource/background/background_0.bmp", renderer);
    logo = LoadImage("../resource/logo/logo_anim_0.bmp", renderer);

    if (!background || !logo)
        exit(1);

    SDL_RenderClear(renderer);

    // TODO split into different functions

    DrawSurface(0, 0, 1600, 900, background, renderer);

    int lW, lH;

    SDL_QueryTexture(logo, NULL, NULL, &lW, &lH);
    int x = 1600 / 2 - lW / 2;
    int y = 800 / 2 - lW / 2;

    DrawSurface(x, y + 400, lW, lH, logo, renderer);

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);

    // TODO Make garabage collector
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(logo);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

//    SDL_Surface *surface   = CreateSurfaceBMP("../resource/logo/logo_anim_0.bmp");
//    SDL_Texture *texture   = CreateTexture(renderer, surface);

//    SDL_RenderClear(renderer);
//    SDL_RenderCopy(renderer, texture, NULL, NULL);
//    SDL_RenderPresent(renderer);
//
//    SDL_Delay(5000);
//
//    SDL_DestroyTexture(texture);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();

    return 0;
}