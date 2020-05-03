#include "game.h"
#include "minilib.h"

/**
 * TODO Main
 */


const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

const int TILE_SIZE = 40;

int GameMain()
{

    InitializeSDL();

    SDL_Window *window = CreateWindow();
    SDL_Renderer *renderer = CreateRenderer(window);

    SDL_Texture *background = LoadTexture("../resource/tiles/tile_01.png", renderer);
    SDL_Texture *logo = LoadTexture("../resource/logo/logo_anim_0.bmp", renderer);

    //Clear the window
    SDL_RenderClear(renderer);

    int xTiles = 640 / 40;
    int yTiles = 480 / 40;

    for (int i = 0; i < xTiles * yTiles; ++i)
    {
        int x = i % xTiles;
        int y = i / xTiles;
        RenderTextureByInput(background, renderer, x * 40, y * 40, 40, 40);
    }

    int iW, iH;
    SDL_QueryTexture(logo, NULL, NULL, &iW, &iH);

    int x = 640 / 2 - iW / 2;
    int y = 480 / 2 - iH / 2;

    RenderTexture(logo, renderer, x, y);

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);

    // TODO Make garabage collector
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(logo);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();


    return 0;
}