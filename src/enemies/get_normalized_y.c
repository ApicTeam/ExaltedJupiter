#include "game.h"

double get_normalized_y(t_baseTexture main_hero, t_enemy *knight){
    return (main_hero.sizeRect.y - knight->windowRect.y) / get_distance_to_hero(main_hero, *(knight));
}

