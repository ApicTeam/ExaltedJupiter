#include "game.h"

bool knight_collision_detect(TextureMap text,t_animation main_hero, t_enemy *knight){
    return (isBackground(text.map[(knight->windowRect.y + knight->windowRect.h/2 + (int)(10 * get_normalized_y(main_hero, knight)))/64]
                                 [(knight->windowRect.x + knight->windowRect.w/3 + (int)(10 * get_normalized_x(main_hero, knight)))/64]))
    || (isBackground(text.map[(knight->windowRect.y + knight->windowRect.h/3 + (int)(10 * get_normalized_y(main_hero, knight)))/64]
                             [(knight->windowRect.x + knight->windowRect.w/2 + (int)(10 * get_normalized_x(main_hero, knight)))/64]))
    || (isBackground(text.map[(knight->windowRect.y + knight->windowRect.h*9/10 + (int)(10 * get_normalized_y(main_hero, knight)))/64]
                             [(knight->windowRect.x + knight->windowRect.w/2 + (int)(10 * get_normalized_x(main_hero, knight)))/64]))
    || (isBackground(text.map[(knight->windowRect.y + knight->windowRect.h/2 + (int)(10 * get_normalized_y(main_hero, knight)))/64]
                             [(knight->windowRect.x + knight->windowRect.w*4/5 + (int)(10 * get_normalized_x(main_hero, knight)))/64]));
}
