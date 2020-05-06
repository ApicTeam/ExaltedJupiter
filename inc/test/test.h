//
// Created by Fight on 5/6/2020.
//

#ifndef EXALTEDJUPITER_DEV_TEST_H
#define EXALTEDJUPITER_DEV_TEST_H

#include "game.h"
#include "minilib.h"
#include "maps.h"

/* Structures */
typedef struct s_app
{
  SDL_Window *window;

  int LevelWidth;
  int LevelHeight;

  int CameraWidth;
  int CameraHeight;

  SDL_Rect View;

  SDL_Renderer *renderer;

  SDL_Event event;

  char *resourceDir;

  bool quit;


}              t_app;

typedef struct s_baseTexture
{
  SDL_Texture *texture;

  int totalFrames;
  int delayPerFrame;

  bool animate;

  SDL_Rect frameRect;
  SDL_Rect sizeRect;

}            t_baseTexture;

typedef struct s_mainHero
{
  int hp;
  int damage;

  int xp;

  char *name;

  int velX;
  int velY;

  t_baseTexture gameData;
}              t_mainHero;


//typedef struct s_enemy
//{
//  int hp;
//  int damage;
//
//  char *name;
//
//  int velX;
//  int velY;
//}              t_enemy;


/* Prototypes */
void StartTemplate(t_app *app);


#endif//EXALTEDJUPITER_DEV_TEMPLATE_HEADER_H
