#include "game.h"
#include "minilib.h"

void CreateApp(t_app app);
void moveHero(t_mainHero *hero, TextureMap text);
void handleEvent(t_app *app, t_mainHero *hero);
int GetTexW(SDL_Texture *texture);
int GetTexH(SDL_Texture *texture);
char *GeneratePath(char *resDir,  char *path);
void animateSprite(t_baseTexture *sprite);

int lvl1[100][100] = {
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,13,13,13,13,13,13,13,13,13,13,13,14,-1,8,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,14,-1,-1,-1,-1,-1 },
    { -1,-1,-1,8,13,13,13,13,13,13,13,13,13,13,14,-1,-1,-1,-1,-1,-1,-1,-1,8,13,13,13,13,13,13,13,13,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,7,7,7,7,7,7,7,7,7,7,7,10,-1,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,10,-1,-1,-1,-1,-1 },
    { -1,-1,-1,9,1,1,1,1,1,1,1,1,1,1,10,-1,-1,-1,-1,-1,-1,-1,-1,9,7,7,7,7,7,7,7,7,7,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,10,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,5,13,13,13,13,14 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,10,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,1,7,7,7,7,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,5,13,13,13,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,10,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,1,7,7,7,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,5,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,10,-1,12,0,0,0,0,0,0,0,0,4,16,16,16,3,0,0,0,0,0,0,4,16,16,16,16,16,16,16,16,3,0,4,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,1,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,10,-1,9,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,10,-1,9,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,0,0,0,4,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,10,-1,9,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,3,0,0,0,0,4,16,16,16,16,16,16,16,3,0,0,0,0,4,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,-1,-1,-1,-1,-1,12,0,0,0,0,0,0,0,0,11,-1,9,16,16,10 },
    { -1,-1,-1,12,0,0,0,0,0,0,0,0,0,0,11,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,8,13,13,13,13,6,16,16,16,5,13,13,13,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,9,7,7,7,7,2,16,16,16,1,7,7,7,7,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10 },
    { -1,-1,-1,8,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,14,-1,12,4,16,16,16,16,16,16,16,3,11,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10 },
    { -1,-1,-1,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,10,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,12,0,0,0,0,0,0,0,11,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,8,13,13,13,13,13,13,13,13,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,5,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,16,16,5,13,13,13,13,13,13,13,13,13,13,13,13,6,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,7,7,7,7,7,7,7,7,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,1,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,16,16,1,7,7,7,7,7,7,7,7,7,7,7,7,2,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,12,0,0,0,4,16,16,16,16,3,0,0,0,0,0,0,0,0,11,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,4,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,12,0,0,0,0,0,0,0,4,16,16,16,16,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,8,13,13,13,13,6,16,16,16,16,16,16,16,5,13,13,13,13,14,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,9,7,7,7,7,2,16,16,16,16,16,16,16,1,7,7,7,7,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,12,0,0,0,0,0,0,0,0,0,11 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,-1,8,13,13,13,6,16,16,16,16,5,13,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,5,13,13,13,13,13,13,13,6,16,16,16,16,5,13,13,13,13,13,13,13,13,13,13,13,13,13,14,-1,-1,-1,-1,12,0,0,0,0,4,16,16,16,3,0,0,0,0,11,-1,-1,8,13,13,13,13,13,13,13,13,13,13,13,13,14 },
    { -1,-1,-1,9,7,7,7,2,16,16,16,16,1,7,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,1,7,7,7,7,7,7,7,2,16,16,16,16,1,7,7,7,7,7,7,7,7,7,7,7,7,7,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,7,7,7,7,7,7,7,7,7,7,7,7,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,3,0,0,4,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,8,13,13,13,13,13,13,6,16,16,16,5,13,13,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,0,0,4,16,16,16,16,3,0,0,0,0,0,0,0,4,16,16,16,16,16,10,-1,-1,9,7,7,7,7,7,7,2,16,16,16,1,7,7,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,5,13,13,6,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,1,7,7,2,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,0,0,4,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,12,0,0,0,4,16,16,16,16,3,0,0,0,11,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,3,0,0,4,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,8,13,13,13,13,6,16,16,16,16,5,13,13,13,13,14,-1,-1,9,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,12,0,0,0,0,0,4,16,16,16,16,16,3,0,0,0,0,0,11,-1,-1,9,7,7,7,7,2,16,16,16,16,1,7,7,7,7,10,-1,-1,9,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,12,0,0,0,0,0,4,16,16,3,0,0,0,11 },
    { -1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10,-1,-1,-1,-1 },
    { -1,8,13,13,13,13,13,6,16,16,16,16,5,13,13,13,13,13,13,13,13,13,14,-1,-1,9,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,8,13,13,13,13,13,13,13,13,13,6,16,16,5,13,13,14,-1 },
    { -1,9,7,7,7,7,7,2,16,16,16,16,1,7,7,7,7,7,7,7,7,7,10,-1,-1,9,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,9,7,7,7,7,7,7,7,7,7,2,16,16,1,7,7,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,5,13,13,13,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,10,-1,-1,12,0,0,0,0,0,0,0,0,0,0,11,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,1,7,7,7,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,5,13,13,6,16,16,16,16,16,10,-1,-1,8,13,13,13,13,13,13,13,13,13,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,1,7,7,2,16,16,16,16,16,10,-1,-1,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,0,11,-1,-1,9,16,16,16,16,16,16,16,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,3,0,0,4,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,5,13,13,13,13,13,13,13,13,13,6,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,1,7,7,7,7,7,7,7,7,7,2,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,10,-1,-1,12,0,0,0,4,16,16,16,16,3,0,0,0,0,0,4,16,16,16,16,3,0,0,0,0,0,4,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,0,0,0,0,4,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,5,13,13,13,13,13,13,6,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1 },
    { -1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,1,7,7,7,7,7,7,2,16,16,16,16,10,-1,-1,-1,-1,8,6,16,16,16,16,5,14,-1,-1,-1,-1,9,16,16,16,16,10,-1 },
    { -1,12,0,0,0,0,4,16,16,16,16,3,0,0,0,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,2,16,16,16,16,1,10,-1,-1,-1,-1,9,16,16,16,16,10,-1 },
    { -1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,5,13,13,13,13,6,16,16,16,16,10,-1 },
    { -1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,12,0,0,0,0,0,0,0,0,0,0,0,0,4,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,1,7,7,7,7,2,16,16,16,16,10,-1 },
    { -1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,3,0,11,-1 },
    { -1,-1,8,13,13,13,6,16,16,16,16,5,13,13,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,8,13,13,13,13,13,13,13,13,13,6,16,16,16,16,10,-1,-1,-1,-1,12,0,0,0,0,0,0,0,4,16,16,16,16,16,16,10,-1,-1,-1 },
    { -1,-1,9,7,7,7,2,16,16,16,16,1,7,7,7,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,9,7,7,7,7,7,7,7,7,7,2,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,5,13,13,13,13,13,13,13,13,13,6,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,5,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,8,13,13,13,13,13,13,13,6,16,16,16,16,16,16,10,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,1,7,7,7,7,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,1,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,7,7,7,7,7,7,7,2,16,16,16,16,16,16,10,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,0,0,0,0,4,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,16,16,16,16,16,5,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,1,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,0,0,0,0,0,0,0,0,0,0,0,0,4,16,16,3,0,0,0,0,0,0,0,0,0,0,0,0,0,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,13,13,13,13,13,13,13,13,6,16,16,16,16,16,3,0,4,16,3,4,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1 },
    { -1,-1,12,0,0,0,0,0,0,4,16,16,3,0,0,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,7,7,7,7,7,7,7,7,2,16,16,16,16,16,10,-1,9,16,10,12,0,0,0,0,0,0,0,0,4,16,16,16,3,0,11,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10,-1,-1,-1,-1,-1,8,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,6,16,16,5,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,14,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,9,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10,-1,-1,-1,-1,-1,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,2,16,16,1,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,9,16,5,13,13,13,13,13,13,13,13,14,9,16,16,16,10,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,3,0,0,0,0,0,0,0,0,0,11,-1,9,16,1,7,7,7,7,7,7,7,7,10,9,16,16,16,10,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,0,0,0,0,0,4,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,9,16,16,16,10,-1,-1,-1,-1,-1 },
    { -1,-1,8,13,13,13,13,13,13,6,16,16,5,13,13,13,13,13,6,16,16,16,16,16,16,3,0,0,0,4,16,16,16,16,16,16,10,-1,-1,-1,8,13,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,5,13,13,6,16,16,16,16,5,13,13,13,13,13,13,13,13,13,13,13,6,16,16,16,16,16,16,16,16,16,16,5,6,16,16,16,10,-1,-1,-1,-1,-1 },
    { -1,-1,9,7,7,7,7,7,7,2,16,16,1,7,7,7,7,7,2,16,16,16,16,16,16,10,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,-1,9,7,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,1,7,7,2,16,16,16,16,1,7,7,7,7,7,7,7,7,7,7,7,2,16,16,16,16,16,16,16,16,16,16,1,2,16,16,16,10,-1,-1,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,9,16,16,16,16,16,16,5,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,9,16,16,16,16,16,16,1,7,7,7,2,16,16,16,3,0,0,4,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,11,-1,-1,-1,-1,-1 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,12,0,0,0,0,0,0,0,0,0,4,16,16,16,3,0,4,16,16,16,16,16,16,10,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,9,16,16,16,16,16,16,10,-1,-1,-1,9,16,16,16,16,16,16,3,0,0,0,4,16,16,16,10,-1,-1,12,0,0,0,0,0,0,0,0,0,0,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,9,16,16,16,16,16,16,10,-1,-1,-1,9,16,16,16,16,16,16,10,-1,-1,-1,9,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,6,16,16,16,10,-1,12,0,0,0,0,0,0,11,8,13,14,12,0,0,0,0,0,0,11,-1,-1,-1,9,16,16,16,10,-1,-1,-1,8,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,14,-1,12,0,0,0,0,4,16,16,16,16,3,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,6,2,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,8,6,7,5,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,-1,-1,-1,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,8,6,2,16,16,16,16,10,-1,8,13,13,13,13,13,13,6,2,16,1,5,13,13,13,13,13,13,13,13,13,14,9,16,16,16,5,13,13,13,6,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,8,6,2,16,16,16,16,16,10,-1,9,7,7,7,7,7,7,2,16,16,16,1,7,7,7,7,7,7,7,7,7,10,9,16,16,16,1,7,7,7,2,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,5,13,13,13,-1,-1,-1,9,16,16,16,16,5,13,13,13,13,13,13,13,13,14,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,8,6,2,16,16,16,16,16,16,10,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,1,7,7,7,10,-1,-1,9,16,16,16,16,1,7,7,7,7,7,7,3,4,10,-1,-1 },
    { -1,-1,-1,-1,-1,-1,8,6,2,16,16,16,16,16,16,16,10,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,9,16,16,16,16,16,3,4,16,16,3,4,16,16,3,4,16,16,3,4,16,16,3,4,16,16,3,4,16,16,3,4,16,16,3,4,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,5,6,10,-1,-1 },
    { -1,-1,-1,-1,-1,8,6,2,16,16,16,16,16,16,16,16,10,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,9,16,16,16,16,16,5,6,16,16,5,6,16,16,5,6,16,16,5,6,16,16,5,6,16,16,5,6,16,16,5,6,16,16,5,6,16,16,16,16,10,-1,-1,9,16,16,16,16,3,0,0,0,0,0,0,0,0,11,-1,-1 },
    { -1,-1,-1,-1,8,6,2,16,16,16,16,16,16,16,16,16,5,13,6,16,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,4,16,16,16,5,6,16,16,16,16,16,1,2,16,16,1,2,16,16,1,2,16,16,1,2,16,16,1,2,16,16,1,2,16,16,1,2,16,16,1,2,16,16,16,16,10,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,-1,8,6,2,16,16,16,16,16,16,16,16,16,16,1,7,2,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,1,2,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,8,13,13,13,13,14 },
    { -1,-1,8,6,2,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,3,0,0,0,0,0,0,11,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,9,7,7,7,7,10 },
    { -1,-1,9,2,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,3,4,16,16,16,16,16,3,4,16,16,3,4,16,16,3,4,16,16,3,4,16,16,3,4,16,16,3,4,16,16,3,4,16,16,3,4,16,16,16,16,10,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,10 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,9,16,16,16,16,16,5,6,16,16,5,6,16,16,5,6,16,16,5,6,16,16,5,6,16,16,5,6,16,16,5,6,16,16,5,6,16,16,16,16,10,-1,-1,9,16,16,16,16,10,-1,-1,-1,-1,-1,9,16,16,16,16,10 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,10,9,16,16,16,16,16,1,2,16,16,1,2,16,16,1,2,16,16,1,2,16,16,1,2,16,16,1,2,16,16,1,2,16,16,1,2,16,16,16,16,10,-1,-1,9,16,16,16,16,5,13,13,13,13,13,6,16,16,16,16,10 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,3,0,0,4,16,16,16,16,16,16,16,10,-1,8,13,13,13,13,13,13,13,13,13,6,16,16,16,10,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,1,7,7,7,7,7,2,16,16,16,16,10 },
    { -1,-1,9,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,10,-1,9,7,7,7,7,7,7,7,7,7,2,16,16,16,10,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10 },
    { -1,-1,12,0,0,0,0,0,0,0,0,0,11,-1,-1,12,0,0,0,0,0,0,0,11,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,5,13,13,6,16,16,16,16,3,0,0,0,0,4,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,16,16,16,16,16,16,16,16,16,16,16,16,16,10,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,1,7,7,2,16,16,16,16,10,-1,-1,-1,-1,9,16,16,16,16,16,10 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,0,0,0,0,0,0,0,0,0,0,0,0,0,11,9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10,-1,-1,-1,-1,12,0,0,0,0,0,11 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },

};

// TODO TODO TODO Delete Junks Files ********************************************************************************************************************************
void StartTemplate(t_app *app)
{

  /* Temp Variables */
  TextureMap text = Map(app->renderer, lvl1);

  /* Initialize Textures */ // TODO Try to wrap it
  t_baseTexture bg =
      {
          .texture = LoadTexture(GeneratePath(app->resourceDir, "/background/Map_1600*1600.png"), app->renderer),
          .sizeRect = {.x = 0, .y = 0, .w = 6400, .h = 6400}
      };


  t_baseTexture Hero =
      {
          .texture = LoadTexture(GeneratePath(app->resourceDir, "/characters/main_hero/idle/hero_idle.png"), app->renderer),
          .totalFrames = 3,
          .delayPerFrame = 189,
          .frameRect = {.x = 0, .y = 0, .w = GetTexW(Hero.texture) / Hero.totalFrames, .h = GetTexH(Hero.texture)},
          .sizeRect = {.x = 400, .y = 350, .w = 192, .h = 192},
      };

  t_mainHero hero;
  create_hero(app->renderer, &hero, Hero);

  /* Create ViewRect */
  app->View.x = 0;
  app->View.y = 0;
  app->View.w = app->CameraWidth;// / 1.175;
  app->View.h = app->CameraHeight;// / 1.175;


  /* Create Hero */
//  t_mainHero hero = {.gameData = Hero, .health = 100, .name = "Hero", .base_damage = 10, .velX = 0, .velY = 0};


  while (!app->quit)
  {
    while (SDL_PollEvent(&app->event))
    {
      if (app->event.type == SDL_QUIT)
        app->quit = true;
      else
        handleEvent(app, &hero);
    }

    SDL_SetRenderDrawColor(app->renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(app->renderer);

    app->View.x = (hero.gameData.sizeRect.x + hero.gameData.sizeRect.w / 2) - app->CameraWidth / 2;
    app->View.y = (hero.gameData.sizeRect.y + hero.gameData.sizeRect.h / 2) - app->CameraHeight / 2;
    app->View.w = 6400;
    app->View.h = 6400;

    if (app->View.x < 0)
      app->View.x = 0;

    if (app->View.y < 0)
      app->View.y = 0;

    if (app->View.x > app->LevelWidth - app->View.w)
       app->View.x = app->LevelWidth - app->View.w;

    if (app->View.y > app->LevelHeight - app->View.h)
       app->View.y = app->LevelHeight - app->View.h;

    moveHero(&hero, text);//app);
    animateSprite(&hero.gameData);
    if(hero_collision_detect(text, hero)) {
         hero.gameData.sizeRect.x -= hero.velX;
         hero.gameData.sizeRect.y -= hero.velY;
    }

    SDL_RenderCopyEx(app->renderer, bg.texture, &app->View, NULL, 0, 0, SDL_FLIP_NONE);

    hero.gameData.sizeRect.x -= app->View.x;
    hero.gameData.sizeRect.y -= app->View.y;

    SDL_RenderCopyEx(app->renderer, hero.gameData.texture, &hero.gameData.frameRect,
                     &hero.gameData.sizeRect, 0, 0, SDL_FLIP_NONE);

    hero.gameData.sizeRect.x += app->View.x;
    hero.gameData.sizeRect.y += app->View.y;

    SDL_RenderPresent(app->renderer);


    SDL_Delay(1000 / 60);
  }

}

void moveHero(t_mainHero *hero, TextureMap text)//t_app *app)
{
    hero->gameData.sizeRect.x += hero->velX;
    hero->gameData.sizeRect.y += hero->velY;


  /*if ((hero->gameData.sizeRect.x < -32) || hero->gameData.sizeRect.x + hero->gameData.sizeRect.w > app->LevelWidth)
    hero->gameData.sizeRect.x -= hero->velX;*/
  /*if((hero->gameData.sizeRect.y < -32) || (hero->gameData.sizeRect.y + hero->gameData.sizeRect.h > app->LevelHeight))
    hero->gameData.sizeRect.y -= hero->velY;*/
}

void animateSprite(t_baseTexture *sprite)
{
  int frame;

  if (sprite->animate)
    frame = (SDL_GetTicks() / sprite->delayPerFrame % sprite->totalFrames);

  else
    frame = 0;


  sprite->frameRect.x = frame * sprite->frameRect.w;
}

void handleEvent(t_app *app, t_mainHero *hero)
{
  SDL_Event e = app -> event;

  if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
  {
    switch (e.key.keysym.sym)
    {
    case SDLK_w:
      hero->velY -= 5;
      hero->gameData.texture = LoadTexture(GeneratePath(app->resourceDir, "/characters/main_hero/run/hero_run_up.png"), app->renderer);
      hero->gameData.totalFrames = 4;
      hero->gameData.animate = true;
      break;

    case SDLK_s:
      hero->velY += 5;
      hero->gameData.texture = LoadTexture(GeneratePath(app->resourceDir, "/characters/main_hero/run/hero_run_down.png"), app->renderer);
      hero->gameData.totalFrames = 4;
      hero->gameData.animate = true;
      break;

    case SDLK_a:
      hero->velX -= 5;
      hero->gameData.texture = LoadTexture(GeneratePath(app->resourceDir, "/characters/main_hero/run/hero_run.png"), app->renderer);
      hero->gameData.totalFrames = 6;
      hero->gameData.animate = true;
      break;
      
    case SDLK_d:
      hero->velX += 5;
      hero->gameData.texture = LoadTexture(GeneratePath(app->resourceDir, "/characters/main_hero/run/hero_run.png"), app->renderer);
      hero->gameData.totalFrames = 6;
      hero->gameData.animate = true;
      break;
    }
  }

  else if (e.type == SDL_KEYUP && e.key.repeat == 0)
  {
    switch (e.key.keysym.sym)
    {
    case SDLK_w:
      hero->velY += 5;
      hero->gameData.texture = LoadTexture(GeneratePath(app->resourceDir, "/characters/main_hero/run/hero_run_up.png"), app->renderer);
      hero->gameData.totalFrames = 4;
      hero->gameData.animate = false;
      break;

    case SDLK_s:
      hero->velY -= 5;
      hero->gameData.texture = LoadTexture(GeneratePath(app->resourceDir, "/characters/main_hero/run/hero_run_down.png"), app->renderer);
      hero->gameData.totalFrames = 4;
      hero->gameData.animate = false;
      break;

    case SDLK_a:
      hero->velX += 5;
      hero->gameData.texture = LoadTexture(GeneratePath(app->resourceDir, "/characters/main_hero/run/hero_run.png"), app->renderer);
      hero->gameData.totalFrames = 6;
      hero->gameData.animate = false;
      break;

    case SDLK_d:
      hero->velX -= 5;
      hero->gameData.texture = LoadTexture(GeneratePath(app->resourceDir, "/characters/main_hero/run/hero_run.png"), app->renderer);
      hero->gameData.totalFrames = 6;
      hero->gameData.animate = false;
      break;
    }
  }
}

char *GeneratePath(char *resDir,  char *path)
{
  char *resPath = calloc(strlen(resDir) + strlen(path), sizeof(char));
  sprintf(resPath, "%s%s", resDir, path);
  return resPath;
}

int GetTexW(SDL_Texture *texture)
{
  int w, h;
  SDL_QueryTexture(texture, NULL, NULL, &w, &h);
  return w;
}
int GetTexH(SDL_Texture *texture)
{
  int w, h;
  SDL_QueryTexture(texture, NULL, NULL, &w, &h);
  return h;
}

void InitializTextures(t_app app)
{

}
