//
// Created by Иван on 03.05.2020.
//
#include "game.h"

#include "minilib.h"



TextureMap Map(SDL_Renderer *renderer, int arr[20][25])
{
    TextureMap text;
    text . wallDown = LoadTexture("../resource/tiles/wall_mid.png", renderer);
    text . wallUp = LoadTexture("../resource/tiles/wall_top_left.png", renderer);
    text . wallLeft = LoadTexture("../resource/tiles/wall_side_mid_left.png", renderer);
    text . wallRight = LoadTexture("../resource/tiles/wall_side_mid_right.png", renderer);

    //LOAD MAP
    for (int row = 0; row < 20; row++)
    {
        for(int column = 0; column < 25; column++)
        {
            text . map[row][column] = arr[row][column];
        }
    }

    text . src.x = text . src.y = 0;

    text . dest.x = text . dest.y = 0;

    text . src.w = text . dest.w = text . src.h = text . dest.h = 64;

    return text;

}


void DrawMap(SDL_Renderer *renderer, TextureMap *text)
{
    int type = 0;

    for (int row = 0; row < 20; row++)
    {
        for(int column = 0; column < 25; column++)
        {
            type = text -> map[row][column];

            text -> dest.x = column * 64;
            text -> dest.y = row * 64;

            switch (type)
            {
                case 1:
                    SDL_RenderCopy(renderer, text -> wallDown, &(text -> src), &(text -> dest));
                    break;
                case 2:
                    SDL_RenderCopy(renderer, text -> wallUp, &(text -> src), &(text -> dest));
                    break;
                case 3:
                    SDL_RenderCopy(renderer, text -> wallLeft, &(text -> src), &(text -> dest));
                    break;
                case 4:
                    SDL_RenderCopy(renderer, text -> wallRight, &(text -> src), &(text -> dest));
                    break;
                default:
                    break;
            }
        }
    }
}
