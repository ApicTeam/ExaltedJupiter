#include "game.h"
/**
 * params
 * SDL_Renderer *renderer
 * t_mainHero *hero
 * */
void create_hero(SDL_Renderer *renderer, t_mainHero *hero, int x_coord, int y_coord){
    hero->windowRect.x = x_coord;
    hero->windowRect.y = y_coord;
    hero->windowRect.w = 150;
    hero->windowRect.h = 150;

    hero->textureRect.x = 0;
    hero->textureRect.y = 0;
    hero->textureRect.w = 0;
    hero->textureRect.h = 0;

    hero->HeroA.windowsRect = &hero->windowRect;
    hero->HeroA.textureRect = &hero->textureRect;
    hero->HeroA.renderer = renderer;
    hero->HeroA.filepath = "../resource/characters/main_hero/idle/hero_idle.png";
    hero->HeroA.delayPerFrame = 255;
    hero->HeroA.totalFrames = 3;

    hero->velX = 0;
    hero->velY = 0;
    hero->health = 100;
    hero->base_damage = 10;
    hero->invulnerability_timer = 0;
    hero->invulnerability = false;
    hero->alive = true;
}