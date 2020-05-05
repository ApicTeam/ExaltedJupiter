#ifndef EXALTEDJUPITER_DEV_GAME_H
#define EXALTEDJUPITER_DEV_GAME_H

/* Includes */
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>

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
    t_animation *tAnimation;

    int hp;
    int attack;
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

//typedef enum e_anim_state
//{
//    IDLE,
//    LEFT,
//    RIGHT,
//    JUMP,
//    ATTACK,
//    TAKE_DAMAGE,
//    DIE
//}            t_anim_state;

/* Prototypes */
    /* Game Parts */
        /* Base Parts*/
            int GameMain();
            void InitializeSDL();
            SDL_Window *CreateWindow(int wW, int wH);
            SDL_Renderer *CreateRenderer(SDL_Window *window);

        /* Render Parts */
            SDL_Texture *LoadTexture(const char *filepath, SDL_Renderer *renderer);
            void RenderTextureByInput(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h);
            void RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y);
//            SDL_Texture *RenderHero(int frame, t_anim_state state, SDL_Renderer *renderer);

        /* Map Part */
        TextureMap Map(SDL_Renderer *renderer, int arr[100][100]);
        void DrawMap(SDL_Renderer *renderer, TextureMap *text);

        /* Main Hero */
        void HeroMove(t_direction direction, int x_vel, int y_vel,  SDL_Rect *windowRect);

        /* levels */
        int Level0Loop();
        void Level1Loop(int wW, int wH);
        void Level2Loop(int wW, int wH);

        /* Animations */
        SDL_Texture *Animation(t_animation *tAnimation);
        SDL_Texture *AnimateByFrames(t_frameanim *tFrameanim);
        t_texture_ss LoadSpriteSheet(SDL_Texture *texture, SDL_Rect textureRect, SDL_Rect frameRect, int frame_count);


/* Utils */
void raise_error(t_error error_id);


#endif // EXALTEDJUPITER_DEV_GAME_H
