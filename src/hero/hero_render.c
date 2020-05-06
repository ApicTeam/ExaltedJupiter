#include "game.h"

void hero_render(SDL_Renderer *renderer, t_mainHero *hero, bool flipped){
    if (!flipped)
        SDL_RenderCopy(renderer, hero->gameData.texture, &hero->gameData.frameRect, &hero->gameData.sizeRect);
    else
        SDL_RenderCopyEx(renderer, hero->gameData.texture, &hero->gameData.frameRect, &hero->gameData.sizeRect, 360, NULL, SDL_FLIP_HORIZONTAL);
}