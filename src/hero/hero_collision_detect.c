#include "game.h"

bool hero_collision_detect(TextureMap text, t_mainHero main_hero){
    return ( isBackground(text.map[(main_hero.windowRect.y + main_hero.windowRect.h/2)/64][(main_hero.windowRect.x + main_hero.windowRect.w/3)/64])
             ||  isBackground(text.map[(main_hero.windowRect.y + main_hero.windowRect.h/3)/64][(main_hero.windowRect.x + main_hero.windowRect.w/2)/64])
             ||  isBackground(text.map[(main_hero.windowRect.y + main_hero.windowRect.h*2/3)/64][(main_hero.windowRect.x + main_hero.windowRect.w/2)/64])
             ||  isBackground(text.map[(main_hero.windowRect.y + main_hero.windowRect.h/2)/64][(main_hero.windowRect.x + main_hero.windowRect.w*2/3)/64]));
}
