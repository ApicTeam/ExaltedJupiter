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
    Level0Loop(1920, 1080);


    Mix_Quit();


    return 0;
}
