#ifndef EXALTEDJUPITER_DEV_STRUCTURES_H
#define EXALTEDJUPITER_DEV_STRUCTURES_H

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

typedef struct s_texture_ss
{
    SDL_Texture *texture;

    int frames_count;

    SDL_Rect texSize;
    SDL_Rect frame;

}               t_texture_ss;


typedef struct Textures
{
    SDL_Texture *backGroundCornerRight;
    SDL_Texture *backGroundCornerLeft;
    SDL_Texture* backGroundWall;
    SDL_Texture* wallDown;
    SDL_Texture* wallUp;
    SDL_Texture* wallLeft;
    SDL_Texture* wallRight;
    SDL_Texture *wallOuterCornerTopLeft;
    SDL_Texture *wallOuterCornerTopRight;
    SDL_Texture *wallOuterCornerDownLeft;
    SDL_Texture *wallOuterCornerDownRight;
    SDL_Texture *wallInnerCornerTopLeft;
    SDL_Texture *wallInnerCornerTopRight;
    SDL_Texture *wallInnerCornerDownLeft;
    SDL_Texture *wallInnerCornerDownRight;
    SDL_Texture *floor;

    SDL_Rect  dest, src ;

    int map[100][100];
}                  TextureMap;

typedef struct s_animation
{
    SDL_Rect *windowsRect;
    SDL_Rect *textureRect;
    SDL_Renderer *renderer;

    char *filepath;
    int delayPerFrame;
    int totalFrames;

    int direction;

}               t_animation;

typedef struct s_frameanim
{
    char *frames_dir;
    SDL_Renderer *renderer;

    int delayPerFrame;
    int totalFrames;

}               t_frameanim;


typedef struct s_enemy
{
    SDL_Rect windowRect;
    SDL_Rect textureRect;
    SDL_Texture *HostileT;
    t_animation HostileA;
    int speed;
    int health;
    int base_damage;
}              t_enemy;

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
    SDL_Rect windowRect;
    SDL_Rect textureRect;
    SDL_Texture *HeroT;
    t_animation HeroA;
    int health;
    int base_damage;
    int xp;
    char *name;
    int velX;
    int velY;
    unsigned int invulnerability_timer;
    bool alive;
    bool invulnerability;
    t_baseTexture gameData;
}              t_mainHero;

/* Enumerations */

typedef enum e_direction
{
    IDLE,
    LEFT,
    RIGHT
}           t_direction;

typedef enum e_error
{
    INIT_ERROR_SDL,
    INIT_ERROR_IMG,
    INIT_ERROR_AUDIO,
    INIT_ERROR_MIXER,
    WINDOWS_ERROR,
    RENDER_ERROR,
    LOAD_TEXTURE_ERROR
}            t_error;

#endif //EXALTEDJUPITER_DEV_STRUCTURES_H
