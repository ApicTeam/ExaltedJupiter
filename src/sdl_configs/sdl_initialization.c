#include "game.h"

void InitializeSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        raise_error(INIT_ERROR_SDL);

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
        raise_error(INIT_ERROR_IMG);

    if (SDL_Init(SDL_INIT_AUDIO) == -1)
        raise_error(INIT_ERROR_AUDIO);

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        raise_error(INIT_ERROR_MIXER);

    if ((Mix_Init(MIX_INIT_MP3) & MIX_INIT_MP3) != MIX_INIT_MP3)
        raise_error(INIT_ERROR_MIXER);

}