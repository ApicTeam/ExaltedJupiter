#include "game.h"
#include "minilib.h"

void raise_error(t_error error_id)
{
    // TODO Check and free memory
    switch (error_id)
    {
        case INIT_ERROR_SDL:
            fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
            SDL_Quit();
            exit(1);

        case INIT_ERROR_IMG:
            fprintf(stderr, "SDL_Image_Init Error: %s\n", IMG_GetError());
            SDL_Quit();
            exit(1);

        case WINDOWS_ERROR:
            fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
            SDL_Quit();
            exit(1);

        case RENDER_ERROR:
            fprintf(stderr, "SDL_CreateRender Error: %s\n", SDL_GetError());
            SDL_Quit();
            exit(1);

        case LOAD_TEXTURE_ERROR:
            fprintf(stderr, "SDL_Image LoadTexture Error: %s\n", IMG_GetError());
            SDL_Quit();
            exit(1);

        default:
            break;
    }
}