#include "game.h"
#include "minilib.h"

SDL_Texture *Animation(t_animation *tAnimation)//SDL_Rect *windowRect, SDL_Rect *textureRect, SDL_Renderer *renderer,
                         //  char *filepath, int delayPerFrame, int totalFrames)
{
    /* Textures */
    SDL_Texture *HeroIdle = LoadTexture(tAnimation->filepath, tAnimation->renderer);

    /* Base Variables */
    int frame = (SDL_GetTicks() / tAnimation->delayPerFrame) % tAnimation->totalFrames;
    int velocity = 0;
    int x_pos = tAnimation->windowsRect->x;
    /* Main Logic */

    /* Initialize Structures */
    if (tAnimation->textureRect -> w == 0 || tAnimation->windowsRect -> w == 0)
    {

        tAnimation->windowsRect -> x = 0;
        tAnimation->windowsRect -> y = 550;
        tAnimation->windowsRect -> w = 150;
        tAnimation->windowsRect -> h = 150;

        tAnimation->textureRect -> x = 0;
        tAnimation->textureRect -> y = 0;

        SDL_QueryTexture(HeroIdle, NULL, NULL, &tAnimation->textureRect->w, &tAnimation->textureRect->h);

        tAnimation->textureRect -> w /= tAnimation->totalFrames;
    }

    tAnimation->textureRect -> x = frame * tAnimation->textureRect -> w;

//    velocity = 0;
//    if (tAnimation->direction == LEFT) velocity = 300;
//    if (tAnimation->direction == RIGHT) velocity = -300;
//    x_pos += velocity / 60;
//    tAnimation->windowsRect->x = x_pos;

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