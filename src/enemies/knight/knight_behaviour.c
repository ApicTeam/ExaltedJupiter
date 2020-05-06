#include "game.h"

void knight_behaviour(t_animation *main_hero, t_enemy *knight, TextureMap text, SDL_Renderer *renderer){
    if(get_distance_to_hero(*(main_hero), *(knight)) < 800.0){
        knight->HostileA.filepath = "../resource/characters/enemy_knight/run/Knight_f_run_spritesheet.png";
        knight->HostileA.totalFrames = 4;
        knight->HostileA.delayPerFrame = 125;
        knight->HostileA.renderer = renderer;
        if (main_hero->windowsRect->x - knight->windowRect.x != 0 || main_hero->windowsRect->y - knight->windowRect.y != 0) {
            double knight_x_vel = knight->speed * get_normalized_x(*(main_hero), knight);
            double knight_y_vel = knight->speed * get_normalized_y(*(main_hero), knight);
            if(!knight_collision_detect(text, *(main_hero), knight))
            {
                HeroMove(0, knight_x_vel, knight_y_vel, &knight->windowRect);
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


