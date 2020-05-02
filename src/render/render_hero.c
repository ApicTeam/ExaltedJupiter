#include "game.h"

SDL_Texture *RenderHero(int frame, t_anim_state state, SDL_Renderer *renderer)
{

    if (state == IDLE)
    {
        char *frames[2] =
                {
                        "../resource/characters/main_hero/idle/anim_0.png",
                        "../resource/characters/main_hero/idle/anim_1.png"
                };

        return LoadTexture(frames[frame], renderer);
    }
    else if (state == LEFT)
    {
        char *frames[6] =
                {
                        "../resource/characters/main_hero/run/base/anim_0.png",
                        "../resource/characters/main_hero/run/base/anim_1.png",
                        "../resource/characters/main_hero/run/base/anim_2.png",
                        "../resource/characters/main_hero/run/base/anim_3.png",
                        "../resource/characters/main_hero/run/base/anim_4.png",
                        "../resource/characters/main_hero/run/base/anim_5.png",
                };

        return LoadTexture(frames[frame], renderer);

    }

}