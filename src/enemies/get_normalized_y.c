#include "game.h"

double get_normalized_y(t_animation main_hero, t_enemy *knight){
    return (main_hero.windowsRect->y - knight->windowRect.y) / get_distance_to_hero(main_hero, *(knight));
}
