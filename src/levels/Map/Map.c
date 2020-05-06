//
// Created by Иван on 03.05.2020.
//
#include "game.h"

#include "minilib.h"



TextureMap Map(SDL_Renderer *renderer, int arr[100][100])
{
    TextureMap text;
    text.backGroundCornerRight = LoadTexture("../resource/tiles/right_corner_wall.png", renderer);
    text.backGroundCornerLeft = LoadTexture("../resource/tiles/left_corner_wall.png", renderer);
    text.backGroundWall = LoadTexture("../resource/tiles/wall_mid.png", renderer);
    text.wallDown = LoadTexture("../resource/tiles/down_wall.png", renderer);
    text.wallUp = LoadTexture("../resource/tiles/wall_top_left.png", renderer);
    text.wallLeft = LoadTexture("../resource/tiles/wall_side_mid_left.png", renderer);
    text.wallRight = LoadTexture("../resource/tiles/wall_side_mid_right.png", renderer);
    text.wallOuterCornerTopLeft = LoadTexture("../resource/tiles/wall_side_down_left.png", renderer);
    text.wallOuterCornerTopRight = LoadTexture("../resource/tiles/wall_side_down_right.png", renderer);
    text.wallOuterCornerDownLeft = LoadTexture("../resource/tiles/wall_side_top_left.png", renderer);
    text.wallOuterCornerDownRight = LoadTexture("../resource/tiles/wall_side_top_right.png", renderer);
    text.wallInnerCornerTopRight = LoadTexture("../resource/tiles/wall_inner_corner_l_top_rigth.png", renderer);
    text.wallInnerCornerTopLeft = LoadTexture("../resource/tiles/wall_inner_corner_l_top_left.png", renderer);
    text.wallInnerCornerDownLeft = LoadTexture("../resource/tiles/top_left_corner.png", renderer);
    text.wallInnerCornerDownRight = LoadTexture("../resource/tiles/top_right_corner.png", renderer);
    text.floor = LoadTexture("../resource/tiles/floor_1.png", renderer);

  //LOAD MAP
    for (int row = 0; row < 100; row++)
    {
        for(int column = 0; column < 100; column++)
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

    for (int row = 0; row < 100; row++)
    {
        for(int column = 0; column < 100; column++)
        {
            type = text -> map[row][column];

            text -> dest.x = column * 64;
            text -> dest.y = row * 64;

            switch (type)
              {
                case 16:
                    SDL_RenderCopy(renderer, text -> floor, &(text -> src), &(text -> dest));
                    break;
                case 2:
                    SDL_RenderCopy(renderer, text -> backGroundCornerRight, &(text -> src), &(text -> dest));
                    break;
                case 1:
                    SDL_RenderCopy(renderer, text -> backGroundCornerLeft, &(text -> src), &(text -> dest));
                    break;
                case 7:
                    SDL_RenderCopy(renderer, text -> backGroundWall, &(text -> src), &(text -> dest));
                    break;
                case 0:
                    SDL_RenderCopy(renderer, text -> wallDown, &(text -> src), &(text -> dest));
                    break;
                case 13:
                    SDL_RenderCopy(renderer, text -> wallUp, &(text -> src), &(text -> dest));
                    break;
                case 9:
                    SDL_RenderCopy(renderer, text -> wallLeft, &(text -> src), &(text -> dest));
                    break;
                case 10:
                    SDL_RenderCopy(renderer, text -> wallRight, &(text -> src), &(text -> dest));
                    break;
                case 11:
                    SDL_RenderCopy(renderer, text -> wallOuterCornerDownLeft, &(text -> src), &(text -> dest));
                    break;
                case 12:
                    SDL_RenderCopy(renderer, text -> wallOuterCornerDownRight, &(text -> src), &(text -> dest));
                    break;
                case 5:
                    SDL_RenderCopy(renderer, text -> wallInnerCornerTopLeft, &(text -> src), &(text -> dest));
                    break;
                case 6:
                    SDL_RenderCopy(renderer, text -> wallInnerCornerTopRight, &(text -> src), &(text -> dest));
                    break;
                case 3:
                    SDL_RenderCopy(renderer, text -> wallInnerCornerDownLeft, &(text -> src), &(text -> dest));
                    break;
                case 4:
                    SDL_RenderCopy(renderer, text -> wallInnerCornerDownRight, &(text -> src), &(text -> dest));
                    break;
                case 14:
                    SDL_RenderCopy(renderer, text -> wallOuterCornerTopLeft, &(text -> src), &(text -> dest));
                    break;
                case 8:
                    SDL_RenderCopy(renderer, text -> wallOuterCornerTopRight, &(text -> src), &(text -> dest));
                    break;
                default:
                    break;
            }
        }
    }
}
