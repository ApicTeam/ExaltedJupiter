#ifndef EXALTEDJUPITER_DEV_STRUCTURES_H
#define EXALTEDJUPITER_DEV_STRUCTURES_H

/* Structures */

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

    SDL_Rect  dest, src ;

    int map[20][25];
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
}              t_enemy;

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
