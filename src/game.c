#include "game.h"

#include "minilib.h"

int frametime = 1;
int FPS = 60;
int SPEED = 300;
int WINDOW_WIDTH = 1600;
int WINDOW_HEIGHT = 800;


/**
 * TODO Main
 * TODO Add error_handler
 */

void InitializeSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        exit(1);
    }
}

SDL_Window *CreateWindow()
{

    /*
     * TODO Pass arguments to function window size (Width, Height) and arguments borderless or fullscreen
     * TODO Create start menu like in unity
     */

    SDL_Window *window = SDL_CreateWindow("Exalted Jupiter", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1600,
                                          800, SDL_WINDOW_BORDERLESS);

    if (!window)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        exit(1);
    }

    return window;
}

SDL_Renderer *CreateRenderer(SDL_Window *window)
{
    /*
     * Hints:
     * -1 to initialize the first one supporting the requested flags
     */
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
    {
        fprintf(stderr, "SDL_CreateRender Error: %s\n", SDL_GetError());
        exit(1);
    }
}
// TODO start
//  make from to function one
SDL_Surface *CreateSurfaceBMP(char *filepath)
{
    SDL_Surface *surface = SDL_LoadBMP(filepath);

    if (!surface)
    {
        fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
        exit(1);
    }

    return surface;
}

SDL_Texture *CreateTexture(SDL_Renderer *renderer, SDL_Surface *surface)
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        exit(1);
    }

    return texture;
}
// TODO End

SDL_Texture *LoadImageBMP(char *filepath, SDL_Renderer *renderer)
{
    /* Variable Definitions */
    SDL_Surface *surface = SDL_LoadBMP(filepath);
    SDL_Texture *texture = NULL;

    if (!surface)
    {
        fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
        exit(1);
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        exit(1);
    }

    return texture;
}

SDL_Texture *LoadImage(char *filepath, SDL_Renderer *renderer)
{
    /* Variable Definitions */
    SDL_Surface *surface = IMG_Load(filepath);
    SDL_Texture *texture = NULL;

    if (!surface)
    {
        fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
        exit(1);
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        exit(1);
    }

    return texture;
}

void DrawSurface(int x, int y, SDL_Texture *texture, SDL_Renderer *renderer)
{
    SDL_Rect position;

    position.x = x;
    position.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &position.x, &position.y);
    SDL_RenderCopy(renderer, texture, NULL, &position);
}

// Starts animation
// Rect is a area to draw
void Animation(char *frameFilePaths[], int frameCount, SDL_Renderer *renderer, SDL_Rect *Rect, float x_pos,
        float y_pos, int *frame)
{

    SDL_Texture *texture = LoadImage(frameFilePaths[*frame], renderer);
    SDL_QueryTexture(texture, NULL, NULL, &Rect->w, &Rect->h);

    Rect->x = (int)x_pos;
    Rect->y = (int)y_pos;

    if(FPS/frametime > 0)
    {
        SDL_RenderClear(renderer);
        texture = LoadImage(frameFilePaths[*frame], renderer);
        SDL_RenderCopy(renderer, texture, NULL, Rect);
        SDL_RenderPresent(renderer);
        if (frametime % 10 == 0)
        {
            (*frame)++;
            if (*frame == frameCount)
                *frame = 0;
        }

    }
}

void PlayerMovement(SDL_Renderer *renderer)
{
    char *filepaths[] = {"../res/Character/rogue like run_Animation 1_0.png",
                         "../res/Character/rogue like run_Animation 1_1.png",
                         "../res/Character/rogue like run_Animation 1_2.png",
                         "../res/Character/rogue like run_Animation 1_3.png",
                         "../res/Character/rogue like run_Animation 1_4.png",
                         "../res/Character/rogue like run_Animation 1_5.png"};

    int framecount = 6;

    SDL_Rect Rect;

    int frame = 0;

    // start sprite in center of screen
    float x_pos = (1600 - Rect.w) / 2;
    float y_pos = (800 - Rect.h) / 2;
    float x_vel = 0;
    float y_vel = 0;

    // keep track of which inputs are given
    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;

    // set to 1 when window close button is pressed
    int close_requested = 0;

    while (!close_requested)
    {
        // process events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    close_requested = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_W:
                        case SDL_SCANCODE_UP:
                            up = 1;
                            break;
                        case SDL_SCANCODE_A:
                        case SDL_SCANCODE_LEFT:
                            left = 1;
                            break;
                        case SDL_SCANCODE_S:
                        case SDL_SCANCODE_DOWN:
                            down = 1;
                            break;
                        case SDL_SCANCODE_D:
                        case SDL_SCANCODE_RIGHT:
                            right = 1;
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_W:
                        case SDL_SCANCODE_UP:
                            up = 0;
                            break;
                        case SDL_SCANCODE_A:
                        case SDL_SCANCODE_LEFT:
                            left = 0;
                            break;
                        case SDL_SCANCODE_S:
                        case SDL_SCANCODE_DOWN:
                            down = 0;
                            break;
                        case SDL_SCANCODE_D:
                        case SDL_SCANCODE_RIGHT:
                            right = 0;
                            break;
                    }
                    break;
            }
        }

        // determine velocity
        x_vel = y_vel = 0;
        if (up && !down) y_vel = -SPEED;
        if (down && !up) y_vel = SPEED;
        if (left && !right) x_vel = -SPEED;
        if (right && !left) x_vel = SPEED;

        // update positions
        x_pos += x_vel / 180;
        y_pos += y_vel / 180;

        // collision detection with bounds
        if (x_pos <= 0) x_pos = 0;
        if (y_pos <= 0) y_pos = 0;
        if (x_pos >= WINDOW_WIDTH - Rect.w) x_pos = WINDOW_WIDTH - Rect.w;
        if (y_pos >= WINDOW_HEIGHT - Rect.h) y_pos = WINDOW_HEIGHT - Rect.h;

        // set the positions in the struct
        Rect.y = (int) y_pos;
        Rect.x = (int) x_pos;


        if (x_vel != 0 || y_vel != 0) Animation(filepaths, framecount, renderer, &Rect, x_pos, y_pos, &frame);

        // wait 1/60th of a second
        frametime++;
        if(frametime == 61) frametime = 1;
    }
}


int GameMain()
{


    InitializeSDL();

    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);

    SDL_Window *window     = CreateWindow();
    SDL_Renderer *renderer = CreateRenderer(window);

    SDL_Texture *texture = LoadImage("../res/background/sbackground.jpg", renderer);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    PlayerMovement(renderer);

//    SDL_RectroyTexture(texture);
//    SDL_RectroyRenderer(renderer);
//    SDL_RectroyWindow(window);
//    SDL_Quit();

    return 0;
}