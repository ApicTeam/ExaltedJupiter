#include "game.h"

bool hero_collision_detect(TextureMap text, t_mainHero main_hero){
    /*return ( isBackground(text.map[(main_hero.gameData.sizeRect.y + main_hero.gameData.sizeRect.h/2)/64][(main_hero.gameData.sizeRect.x + main_hero.gameData.sizeRect.w/3)/64])
             ||  isBackground(text.map[(main_hero.gameData.sizeRect.y + main_hero.gameData.sizeRect.h/3)/64][(main_hero.gameData.sizeRect.x + main_hero.gameData.sizeRect.w/2)/64])
             ||  isBackground(text.map[(main_hero.gameData.sizeRect.y + main_hero.gameData.sizeRect.h*2/3)/64][(main_hero.gameData.sizeRect.x + main_hero.gameData.sizeRect.w/2)/64])
             ||  isBackground(text.map[(main_hero.gameData.sizeRect.y + main_hero.gameData.sizeRect.h/2)/64][(main_hero.gameData.sizeRect.x + main_hero.gameData.sizeRect.w*2/3)/64]));*/

    if(isBackground(text.map[(main_hero.gameData.sizeRect.y + main_hero.gameData.sizeRect.h/2)/64][(main_hero.gameData.sizeRect.x + main_hero.gameData.sizeRect.w/3)/64])){
        SDL_Log("tile %d:", text.map[(main_hero.gameData.sizeRect.y + main_hero.gameData.sizeRect.h/2)/64][(main_hero.gameData.sizeRect.x + main_hero.gameData.sizeRect.w/3)/64]);
        return true;
    }
}