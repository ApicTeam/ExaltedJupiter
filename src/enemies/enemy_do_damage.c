#include "game.h"

void enemy_do_damage(t_mainHero *mainHero, t_enemy enemy){
    mainHero->health -= enemy.base_damage;
    mainHero->invulnerability = true;
    mainHero->invulnerability_timer = SDL_GetTicks();
    if(mainHero->health <= 0)
        mainHero->alive = false;
    SDL_Log("health %d", mainHero->health);
}

