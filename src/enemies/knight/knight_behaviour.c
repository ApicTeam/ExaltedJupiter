#include "game.h"

void knight_behaviour(t_animation main_hero, t_enemy *knight, TextureMap text, SDL_Renderer *renderer){
    if(get_distance_to_hero(main_hero, *(knight)) < 800.0){
        knight->HostileA.filepath = "../resource/characters/enemy_knight/run/Knight_f_run_spritesheet.png";
        knight->HostileA.totalFrames = 4;
        knight->HostileA.delayPerFrame = 125;
        knight->HostileA.renderer = renderer;
        if (main_hero.windowsRect->x - knight->windowRect.x != 0 || main_hero.windowsRect->y - knight->windowRect.y != 0) {
            double knight_x_vel = 240 * ((main_hero.windowsRect->x - knight->windowRect.x) /
                                         sqrt(pow(main_hero.windowsRect->x - knight->windowRect.x, 2) +
                                              pow(main_hero.windowsRect->y - knight->windowRect.y, 2)));
//            SDL_Log("x: %f\n", knight_x_vel);
            double knight_y_vel = 240 * ((main_hero.windowsRect->y - knight->windowRect.y) /
                                         sqrt(pow(main_hero.windowsRect->x - knight->windowRect.x, 2) +
                                              pow(main_hero.windowsRect->y - knight->windowRect.y, 2)));
//            SDL_Log("y: %f\n", knight_y_vel);
            if(text.map[(knight->windowRect.y + knight->windowRect.h/2)/64][(knight->windowRect.x + knight->windowRect.w/3)/64] > 0
               || text.map[(knight->windowRect.y + knight->windowRect.h/3)/64][(knight->windowRect.x + knight->windowRect.w/2)/64] > 0
               || text.map[(knight->windowRect.y + knight->windowRect.h*9/10)/64][(knight->windowRect.x + knight->windowRect.w/2)/64] > 0
               || text.map[(knight->windowRect.y + knight->windowRect.h/2)/64][(knight->windowRect.x + knight->windowRect.w*2/3)/64] >0){
                HeroMove(0, -knight_x_vel, -knight_y_vel, &knight->windowRect);
            }
            else
                HeroMove(0, knight_x_vel, knight_y_vel, &knight->windowRect);
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


