#include "game.h"

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
        /*tAnimation->windowsRect -> x = 300;
        tAnimation->windowsRect -> y = 250;
        tAnimation->windowsRect -> w = 150;
        tAnimation->windowsRect -> h = 150;*/

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