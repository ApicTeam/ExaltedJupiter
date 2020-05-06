#include "game.h"

double get_normalized_x(t_animation main_hero, t_enemy *knight){
    return (main_hero.windowsRect->x - knight->windowRect.x) / get_distance_to_hero(main_hero, *(knight));
}