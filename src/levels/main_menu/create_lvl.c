#include "game.h"
#include "minilib.h"
#include "main_menu/mm_lib.h"

typedef struct s_level
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Texture **texuterArray;
}              t_level;


t_level levelStruct;

void init()
{
    /* Base initialization */
    levelStruct.window = CreateWindow(500, 475);
    levelStruct.renderer = CreateRenderer(levelStruct.window);

    /* Texture initialization */ // TODO Make code more cleaner // Add level resource path
//    SDL_Texture *playBtn = LoadTexture("../resource/buttons/main_menu/play_ss.png", levelStruct.renderer);
//    levelStruct.texuterArray[0] = playBtn;
}

int Level0Loop()
{

    /* Base Variables */
    init();


    /* Music */
    Mix_Music *bgMusic = Mix_LoadMUS("../resource/music/Ruined.mp3");

    if (!bgMusic)
        exit(5);

    /* Texture */
    SDL_Texture *bgT;
    SDL_Texture *logoT;

    /* Buttons */
    SDL_Texture *playBtnT = LoadTexture("../resource/buttons/main_menu/play_ss.png", levelStruct.renderer);

    SDL_Rect playBtnTextureRect = {.x = 175, .y = 375, .w = 150, .h = 70};
    SDL_Rect playBtnFrameRect = {.x = 0, .y = 0};
    t_texture_ss playBtn = LoadSpriteSheet(playBtnT, playBtnTextureRect, playBtnFrameRect, 2);


    /* Frames */
    t_frameanim bg;
    bg.frames_dir = "../resource/background/main_menu/frame_";
    bg.totalFrames = 8;
    bg.renderer = levelStruct.renderer;
    bg.delayPerFrame = 100;

    t_frameanim logo;
    logo.frames_dir = "../resource/logo/frame_";
    logo.totalFrames = 4;
    logo.renderer = levelStruct.renderer;
    logo.delayPerFrame = 100;

    SDL_Event event;

    /* Level Loop */
    bool quit = false;
    bool next = false;

    Mix_PlayMusic(bgMusic, -1);

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                quit = true;

            else if (event.type == SDL_KEYUP || event.type == SDL_KEYDOWN)
                break;

        }

        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);

        bgT = AnimateByFrames(&bg);
        logoT = AnimateByFrames(&logo);

        SDL_SetRenderDrawColor(levelStruct.renderer, 0, 0, 0, 255);
        SDL_RenderClear(levelStruct.renderer);

        RenderTexture(bgT, levelStruct.renderer, 0, 0);
        RenderTextureByInput(logoT, levelStruct.renderer, 75, 0, 350, 100);

        SDL_Log("m_x = %d || m_y = %d", mouse_x, mouse_y);
        if (mouse_x >= 180 && mouse_x <= 314 &&  mouse_y >= 380 && mouse_y <= 440)
        {
            playBtn.frame.x = 300;
            SDL_RenderCopy(levelStruct.renderer, playBtn.texture, &playBtn.frame, &playBtn.texSize);

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                next = true;
                quit = true;
            }
        }
        else
        {
            playBtn.frame.x = 0;
            SDL_RenderCopy(levelStruct.renderer, playBtn.texture, &playBtn.frame, &playBtn.texSize);
        }
        SDL_Delay(1000/60);
        SDL_RenderPresent(levelStruct.renderer);
    }

    SDL_DestroyTexture(playBtnT);
    SDL_DestroyTexture(bgT);
    SDL_DestroyTexture(logoT);
    SDL_DestroyRenderer(levelStruct.renderer);
    SDL_DestroyWindow(levelStruct.window);

    if (next)
    {
        Mix_FreeMusic(bgMusic);
        Level2Loop(1600, 800);
    }
    IMG_Quit();
    SDL_Quit();

    return 0;
}
