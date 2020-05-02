#ifndef EXALTEDJUPITER_DEV_GAME_H
#define EXALTEDJUPITER_DEV_GAME_H

/* Includes */
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

/* Enumerations */
typedef enum e_error
{
    INIT_ERROR_SDL,
    INIT_ERROR_IMG,
    WINDOWS_ERROR,
    RENDER_ERROR,
    LOAD_TEXTURE_ERROR
}            t_error;

typedef enum e_anim_state
{
    IDLE,
    LEFT,
    RIGHT,
    JUMP,
    ATTACK,
    TAKE_DAMAGE,
    DIE
}            t_anim_state;

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
            SDL_Texture *RenderHero(int frame, t_anim_state state, SDL_Renderer *renderer);

        /* Main Hero */
        void HeroMove(SDL_Scancode key, int state);

        /* Levels */
        int Level0Loop();
        void Level1Loop();

/* Utils */
void raise_error(t_error error_id);


#endif // EXALTEDJUPITER_DEV_GAME_H
