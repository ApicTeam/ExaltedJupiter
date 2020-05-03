#ifndef EXALTEDJUPITER_DEV_GAME_H
#define EXALTEDJUPITER_DEV_GAME_H

/* Includes */
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

/* Structures */

typedef struct Textures
{
    SDL_Texture* wallDown;
    SDL_Texture* wallUp;
    SDL_Texture* wallLeft;
    SDL_Texture* wallRight;

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
            SDL_Window *CreateWindow();
            SDL_Renderer *CreateRenderer(SDL_Window *window);

        /* Render Parts */
            SDL_Texture *LoadTexture(const char *filepath, SDL_Renderer *renderer);
            void RenderTextureByInput(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h);
            void RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y);
//            SDL_Texture *RenderHero(int frame, t_anim_state state, SDL_Renderer *renderer);

        /* Map Part */
        TextureMap *Map(SDL_Renderer *renderer, int arr[20][25]);
        void DrawMap(SDL_Renderer *renderer, TextureMap *text);

        /* Main Hero */
        void HeroMove(t_direction direction, int x_pos, int y_pos,  SDL_Rect *windowRect);

        /* Levels */
        int Level0Loop();
        void Level1Loop();

        /* Animations */
        SDL_Texture *Animation(t_animation *tAnimation);

/* Utils */
void raise_error(t_error error_id);


#endif // EXALTEDJUPITER_DEV_GAME_H
