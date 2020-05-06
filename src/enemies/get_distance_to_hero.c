#include "game.h"

double get_distance_to_hero(t_animation main_hero, t_enemy enemy){
    return sqrt(pow(main_hero.windowsRect->x - enemy.windowRect.x, 2) + pow(main_hero.windowsRect->y - enemy.windowRect.y, 2));
}