#include "game.h"
// #include "maps.h"

SDL_Renderer *renderer = NULL;

int lvl1[16][30] = {
    {8,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,14},
    {9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {9,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,10},
    {12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11}
};


    bool isBackround(int h)
{
  return (h != 16 && h != 1 && h != 2 && h != 7);
}

void handleAttack(t_enemy *knight, t_mainHero *main_hero)
{

  Mix_Chunk *attackSound = Mix_LoadWAV("../resource/music/damage/attack.mp3");
  if (!attackSound)
    SDL_Log("%s", Mix_GetError());

  Mix_PlayChannel(1, attackSound, 0);

    if (main_hero->HeroA.windowsRect->x - knight->windowRect.x < 10 || main_hero->HeroA.windowsRect->y - knight->windowRect.y < 10)
  {
      if (knight->health <= 0)
      {
        knight->alive = false;
        knight->base_damage = 0;
      }
      knight->health -= main_hero->base_damage;
    }
}


// void Level2Loop(int wW, int wH)
void Level2Loop()
{
  /* Music */
  Mix_Chunk *stepSound = Mix_LoadWAV("../resource/music/hero_sound/steps.mp3");
  if (!stepSound)
    SDL_Log("%s", Mix_GetError());

  Mix_Music *musicFone = Mix_LoadMUS("../resource/music/Crasher.mp3");
  Mix_PlayMusic(musicFone, 0);

  SDL_Rect camera = {0, 0, 1920, 1080};
  /* Base Variables */
  SDL_Window *window = CreateWindow(1920, 1080);
  renderer = CreateRenderer(window);

  SDL_Event event;
  bool quit = false;
  Mix_AllocateChannels(3);
  /* Textures */
  SDL_Texture *Background = LoadTexture("../resource/background/background_1.png", renderer);
  TextureMap text = Map(renderer, lvl1);
  /* Make Rectangles */

  //'windowRect' defines the dimensions of the rendering sprite on window
  SDL_Rect windowRect = {.x = 0,.y = 0, .w = 0, .h = 0};

  //'textureRect' defines the dimensions of the rendering sprite on texture
  // SDL_Rect textureRect = {.x = 0, .y = 0, .w = 0, .h = 0};

  // int totalFrames = 6;
  // int delayPerFrame = 157.835782842584534950903505000099999990999090905949;
  // int delayPerFrame = 157;
  int anim = false;

  /*HERO CREATION*/
  t_mainHero hero;
  create_hero(renderer, &hero, 400, 350);

  /*KNIGHT TEST*/
  t_enemy knights[9];

      create_knight(renderer, &knights[0], 100, 100);
      create_knight(renderer, &knights[1], 300, 100);
      create_knight(renderer, &knights[2], 100, 300);
      create_knight(renderer, &knights[3], 500, 100);
      create_knight(renderer, &knights[4], 800, 100);
      create_knight(renderer, &knights[5], 700, 50);
      create_knight(renderer, &knights[6], 500, 250);
      create_knight(renderer, &knights[7], 300, 300);
      create_knight(renderer, &knights[8], 300, 300);

/**/
  // int scene_counter = 0;
  int left = 0;
  int right = 0;
  int up = 0;
  int down = 0;

  int dir = 0;


  int flip = false;


  while (!quit)
  {

    if (!hero.alive)
    {
      SDL_RenderClear(renderer);
      SDL_Texture *gameOver = LoadTexture("../resource/background/gameOver.png", renderer);
      RenderTexture(gameOver, renderer, 0, 0);
      SDL_RenderPresent(renderer);

      SDL_Delay(5000);
      SDL_WaitEvent(&event);

      if (event.type == SDL_KEYDOWN) {
        quit = true;
        break;
      }
    }


    anim = false;
    int wasLeft = false;

    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT) quit = true;

      if (event.type == SDL_KEYDOWN)
      {
        if (event.key.keysym.scancode == SDL_SCANCODE_W)
        {
          up = 1;
          dir = 3;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_S)
        {
          down = 1;
          dir = 4;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_D)
        {
          flip = false;
          right = 1;
          dir = 2;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_A)
        {
          left = 1;
          dir = 1;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
        {
          for (int knight = 0; knight < 8; ++knight)
          {
              handleAttack(&knights[knight], &hero);
          }
        }
      }
      else if (event.type == SDL_KEYUP)
      {
        if (event.key.keysym.scancode == SDL_SCANCODE_D)
        {
          wasLeft = false;
          right = 0;
          dir = 0;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_A)
        {
          flip = false;
          wasLeft = true;
          left = 0;
          dir = 0;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_W)
        {
          up = 0;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_S)
        {
          down = 0;
        }
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // TODO Fix multiply touch W/A or S/D
    if (!left && !right && !down && !up)
    {
      if (Mix_Playing(0))
      {
        SDL_Log("Stop Music");
        Mix_HaltChannel(0);
      }
      hero.HeroA.filepath = "../resource/characters/main_hero/idle/hero_idle.png";
      hero.HeroA.totalFrames = 3;
      hero.HeroA.delayPerFrame = 255;
      if(wasLeft)
        flip = true;
    }

    if (left && up)
    {
      hero.HeroA.filepath = "../resource/characters/main_hero/run/hero_run.png";
      hero.HeroA.totalFrames = 6;
      hero.HeroA.delayPerFrame = 100;
      hero.velX = -300;
      hero.velY = -300;
      HeroMove(hero.velX, hero.velY, &hero.windowRect);
      flip = true;
    }
    else if (left && down)
    {
      hero.HeroA.filepath = "../resource/characters/main_hero/run/hero_run.png";
      hero.HeroA.totalFrames = 6;
      hero.HeroA.delayPerFrame = 100;
      hero.velX = -300;
      hero.velY = 300;
      HeroMove(hero.velX, hero.velY, &hero.windowRect);
      flip = true;
    }
    else if (right && up)
    {
      hero.HeroA.filepath = "../resource/characters/main_hero/run/hero_run.png";
      hero.HeroA.totalFrames = 6;
      hero.HeroA.delayPerFrame = 100;
      hero.velX = 300;
      hero.velY = -300;
      HeroMove(hero.velX, hero.velY, &hero.windowRect);
    }
    else if (right && down)
    {
      hero.HeroA.filepath = "../resource/characters/main_hero/run/hero_run.png";
      hero.HeroA.totalFrames = 6;
      hero.HeroA.delayPerFrame = 100;
      hero.velX = 300;
      hero.velY = 300;
      HeroMove(hero.velX, hero.velY, &hero.windowRect);
    }
    else if (left)
    {
      hero.HeroA.filepath = "../resource/characters/main_hero/run/hero_run.png";
      hero.HeroA.totalFrames = 6;
      hero.HeroA.delayPerFrame = 100;
      hero.velX = -300;
      hero.velY = 0;
      HeroMove(hero.velX, hero.velY, &hero.windowRect);
      flip = true;
    }
    else if (right)
    {
      hero.HeroA.filepath = "../resource/characters/main_hero/run/hero_run.png";
      hero.HeroA.totalFrames = 6;
      hero.HeroA.delayPerFrame = 100;
      hero.velX = 300;
      hero.velY = 0;
      HeroMove(hero.velX, hero.velY, &hero.windowRect);
    }
    else if (up)
    {
      hero.HeroA.filepath = "../resource/characters/main_hero/run/hero_run_up.png";
      hero.HeroA.totalFrames = 4;
      hero.HeroA.delayPerFrame = 100;
      hero.velX = 0;
      hero.velY = -300;
      HeroMove(hero.velX, hero.velY, &hero.windowRect);
    }
    else if (down)
    {
      hero.HeroA.filepath = "../resource/characters/main_hero/run/hero_run_down.png";
      hero.HeroA.totalFrames = 4;
      hero.HeroA.delayPerFrame = 100;
      hero.velX = 0;
      hero.velY = 300;
      HeroMove(hero.velX, hero.velY, &hero.windowRect);
    }

    if (up || down || left || right) {
      if (!Mix_Playing(0))
        Mix_PlayChannel(0, stepSound, 0);
    }

//KNIGHT BEHAVIOUR
    for(int i = 0; i < 8; i++)
        knight_behaviour(&hero, &knights[i], text, renderer);
    //END
      hero.HeroT = Animation(&hero.HeroA);

    camera.x = windowRect.x - 800;
    camera.y = windowRect.y - 400;

    if(hero_collision_detect(text, hero))
    {
      HeroMove(-hero.velX, -hero.velY, &hero.windowRect);
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    RenderTextureByInput(Background, renderer, 0, 0, 1920, 1080);
    DrawMap(renderer, &text);
    //Copying the texture on to the window using
    //renderer, texture rectangle and window rectangle
    hero_render(renderer, &hero, flip);
//    KNIGHT RENDER
      for(int i = 0; i < 8; i++)
        if (knights[i].alive == true)
          knight_render(renderer, &knights[i], false);

    SDL_Delay(1000/60);
    SDL_RenderPresent(renderer);


    //    SDL_Log("Scene: %d\n\n", scene_counter++);

  }


  SDL_DestroyTexture(Background);
  SDL_DestroyTexture(hero.HeroT);

  for (int j = 0; j < 8 ; ++j) {
    SDL_DestroyTexture(knights[j].HostileT);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  Mix_Quit();
  SDL_Quit();

}
