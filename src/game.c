#include "game.h"
#include "minilib.h"

/**
 * TODO Main
 */


int GameMain()
{
    InitializeSDL();

    /* Create Main Menu*/
    /*
     * Logic For Create Main Menu
     * У мейн меню будет свой геймлуп
     * Вся логики и анимация будет проходить внутри
     * Локального геймлупа src/level/main_menu/ *.[c]
     */

    /* Create Level 0 */
    // Level2Loop(1600, 800);
    /* Temp Data */
    t_app app = {.window = CreateWindow(1920, 1080), .renderer = CreateRenderer(app.window), .LevelWidth = 6400, .LevelHeight = 6400,
        .quit = false, .resourceDir = "../resource", .CameraWidth = 1920, .CameraHeight = 1080};


    /* Create Level 0 */
    StartTemplate(&app);

    Mix_Quit();


    return 0;
}