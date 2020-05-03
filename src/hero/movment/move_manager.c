#include "game.h"
#include "minilib.h"

void HeroMove(t_direction direction, int x_pos, int y_pos,  SDL_Rect *windowRect)
{
    /* Variable Definitions */
    int x_vel = 0;

    if (direction == 1 || direction == 4) x_vel = -300;
    if (direction == 2 || direction == 3) x_vel =  300;

    windowRect->x += x_pos / 60;
    windowRect->y += y_pos / 60;
}