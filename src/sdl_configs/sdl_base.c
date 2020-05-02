#include "game.h"

SDL_Window *CreateWindow()
{

    /*
     * TODO Pass arguments to function window size (Width, Height) and arguments borderless or fullscreen
     * TODO Create start menu like in unity
     */

    SDL_Window *window = SDL_CreateWindow("Exalted Jupiter", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1600,
                                          800, 0);

    if (!window)
        raise_error(WINDOWS_ERROR);

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
        SDL_DestroyWindow(window);
        raise_error(RENDER_ERROR);
    }

    return renderer;
}