#include "game.h"

void hero_render(SDL_Renderer *renderer, t_mainHero *hero, bool flipped){
    if (!flipped)
        SDL_RenderCopy(renderer, hero->HeroT, &hero->textureRect, &hero->windowRect);
    else
        SDL_RenderCopyEx(renderer, hero->HeroT, &hero->textureRect, &hero->windowRect, 360, NULL, SDL_FLIP_HORIZONTAL);
}