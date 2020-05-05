#include "game.h"
/**
 * params SDL_Renderer *renderer
 * params t_enemy *knight*/
void *create_knight(SDL_Renderer *renderer, t_enemy *knight, int x_coord, int y_coord){
        knight->windowRect.x = x_coord;
        knight->windowRect.y = y_coord;
        knight->windowRect.w = 80;
        knight->windowRect.h = 110;

        knight->textureRect.x = 0;
        knight->textureRect.y = 0;
        knight->textureRect.w = 0;
        knight->textureRect.h = 0;

        knight->HostileA.windowsRect = &knight->windowRect;
        knight->HostileA.textureRect = &knight->textureRect;
        knight->HostileA.renderer = renderer;
        knight->HostileA.filepath = "../resource/characters/enemy_knight/idle/Knight_f_idle_spritesheet.png";
        knight->HostileA.delayPerFrame = 255;
        knight->HostileA.totalFrames = 4;
}

