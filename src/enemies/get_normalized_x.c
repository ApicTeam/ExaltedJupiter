#include "game.h"

double get_normalized_x(t_baseTexture main_hero, t_enemy *knight){
    return (main_hero.sizeRect.x - knight->windowRect.x) / get_distance_to_hero(main_hero, *(knight));
}