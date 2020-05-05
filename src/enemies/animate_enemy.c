#include "game.h"

SDL_Texture *animate_enemy(t_animation *tAnimation)
{
    /* Textures */
    SDL_Texture *enemy_texture = LoadTexture(tAnimation->filepath, tAnimation->renderer);
    /* Base Variables */
    int frame = (SDL_GetTicks() / tAnimation->delayPerFrame) % tAnimation->totalFrames;
    if (tAnimation->textureRect -> w == 0 || tAnimation->windowsRect -> w == 0)
    {
        tAnimation->textureRect -> x = 0;
        tAnimation->textureRect -> y = 0;

        SDL_QueryTexture(enemy_texture, NULL, NULL, &tAnimation->textureRect->w, &tAnimation->textureRect->h);

        tAnimation->textureRect -> w /= tAnimation->totalFrames;
    }

    tAnimation->textureRect -> x = frame * tAnimation->textureRect -> w;
    tAnimation->textureRect -> x = frame * tAnimation->textureRect -> w;
    return enemy_texture;
}