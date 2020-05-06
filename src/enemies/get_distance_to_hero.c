#include "game.h"

double get_distance_to_hero(t_baseTexture main_hero, t_enemy enemy){
    return sqrt(pow(main_hero.sizeRect.x - enemy.windowRect.x, 2) + pow(main_hero.sizeRect.y - enemy.windowRect.y, 2));
}