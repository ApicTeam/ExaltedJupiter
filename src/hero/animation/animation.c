#include "game.h"
#include "minilib.h"

SDL_Texture *Animation(t_animation *tAnimation)//SDL_Rect *windowRect, SDL_Rect *textureRect, SDL_Renderer *renderer,
                         //  char *filepath, int delayPerFrame, int totalFrames)
{
    /* Textures */
    SDL_Texture *HeroIdle = LoadTexture(tAnimation->filepath, tAnimation->renderer);

    /* Base Variables */
    int frame = (SDL_GetTicks() / tAnimation->delayPerFrame) % tAnimation->totalFrames;

    /* Main Logic */

    /* Initialize Structures */
    if (tAnimation->textureRect -> w == 0 || tAnimation->windowsRect -> w == 0)
    {

        tAnimation->windowsRect -> x = 0;
        tAnimation->windowsRect -> y = 0;
        tAnimation->windowsRect -> w = 150;
        tAnimation->windowsRect -> h = 150;

        tAnimation->textureRect -> x = 0;
        tAnimation->textureRect -> y = 0;

        SDL_QueryTexture(HeroIdle, NULL, NULL, &tAnimation->textureRect->w, &tAnimation->textureRect->h);

        tAnimation->textureRect -> w /= tAnimation->totalFrames;
    }

    tAnimation->textureRect -> x = frame * tAnimation->textureRect -> w;

    return HeroIdle;
}

SDL_Texture *RunAnimation(SDL_Rect *windowRect, SDL_Rect *textureRect, SDL_Renderer *renderer)
{
    /* Textures */
    SDL_Texture *HeroIdle = LoadTexture("../resource/characters/main_hero/run/hero_run.png", renderer);

    /* Base Variables */
    int delayPerFrame = 100;
    int totalFrames = 6;
    int frame = (SDL_GetTicks() / delayPerFrame) % totalFrames;

    /* Main Logic */

    /* Initialize Structures */
    if (textureRect -> w == 0 || windowRect -> w == 0)
    {

        windowRect -> x = 0;
        windowRect -> y = 0;
        windowRect -> w = 150;
        windowRect -> h = 150;

        textureRect -> x = 0;
        textureRect -> y = 0;

        SDL_QueryTexture(HeroIdle, NULL, NULL, &textureRect->w, &textureRect->h);

        textureRect -> w /= totalFrames;
    }

    textureRect -> x = frame * textureRect -> w;

    return HeroIdle;
}