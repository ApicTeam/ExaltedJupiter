#include "game.h"

void knight_behaviour(t_mainHero *main_hero, t_enemy *knight, TextureMap text, SDL_Renderer *renderer){
    if(get_distance_to_hero(main_hero->gameData, *(knight)) < 800.0){
        knight->HostileA.filepath = "../resource/characters/enemy_knight/run/Knight_f_run_spritesheet.png";
        knight->HostileA.totalFrames = 4;
        knight->HostileA.delayPerFrame = 125;
        knight->HostileA.renderer = renderer;
        if (main_hero->gameData.sizeRect.x - knight->windowRect.x != 0 || main_hero->gameData.sizeRect.y - knight->windowRect.y != 0) {
            SDL_Log("move");
            double knight_x_vel = knight->speed * get_normalized_x(main_hero->gameData, knight);
            double knight_y_vel = knight->speed * get_normalized_y(main_hero->gameData, knight);
            if(!knight_collision_detect(text, main_hero->gameData, knight))
                HeroMove(0, knight_x_vel, knight_y_vel, &knight->windowRect);
            if(main_hero->gameData.sizeRect.x - knight->windowRect.x < 10 || main_hero->gameData.sizeRect.y - knight->windowRect.y < 10){
                if(!main_hero->invulnerability)
                    enemy_do_damage(main_hero, *(knight));
                else if(SDL_GetTicks() - main_hero->invulnerability_timer > 1000)
                    main_hero->invulnerability = false;
            }
        }
    }
    else{
        knight->HostileA.filepath = "../resource/characters/enemy_knight/idle/Knight_f_idle_spritesheet.png";
        knight->HostileA.totalFrames = 4;
        knight->HostileA.delayPerFrame = 150;
        knight->HostileA.renderer = renderer;
    }
    knight->HostileT = animate_enemy(&(knight->HostileA));
}


