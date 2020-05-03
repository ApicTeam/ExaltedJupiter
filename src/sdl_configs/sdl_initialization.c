#include "game.h"

void InitializeSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        raise_error(INIT_ERROR_SDL);

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
        raise_error(INIT_ERROR_IMG);

}