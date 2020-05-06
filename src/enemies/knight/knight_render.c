#include "game.h"

void knight_render(SDL_Renderer *renderer, t_enemy *knight, bool flipped){
    if(!flipped)
        SDL_RenderCopy(renderer, knight->HostileT, &knight->textureRect, &knight->windowRect);
    else
        SDL_RenderCopyEx(renderer, knight->HostileT, &(knight->textureRect), &(knight->windowRect), 360, NULL, SDL_FLIP_HORIZONTAL);
}
