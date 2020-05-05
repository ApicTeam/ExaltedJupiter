#ifndef EXALTEDJUPITER_DEV_GAME_H
#define EXALTEDJUPITER_DEV_GAME_H

/* Includes */
#include "minilib.h"

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
        TextureMap Map(SDL_Renderer *renderer, int arr[20][25]);
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

        /*Enemies*/
        double get_distance_to_hero(t_animation, t_enemy);
        SDL_Texture *animate_enemy(t_animation *);
        void *create_knight(SDL_Renderer *, t_enemy *, int, int);
        void knight_behaviour(t_animation, t_enemy *, TextureMap, SDL_Renderer *);
        void knight_render(SDL_Renderer *, t_enemy *, bool);

/* Utils */
void raise_error(t_error error_id);


#endif // EXALTEDJUPITER_DEV_GAME_H
