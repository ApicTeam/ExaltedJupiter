#include "game.h"
/**
 * params
 * SDL_Renderer *renderer
 * t_mainHero *hero
 * */
void create_hero(SDL_Renderer *renderer, t_mainHero *hero, t_baseTexture gameData){
    hero->velX = 0;
    hero->velY = 0;
    hero->health = 100;
    hero->base_damage = 10;
    hero->invulnerability_timer = 0;
    hero->invulnerability = false;
    hero->alive = true;
    hero->gameData = gameData;
}