#include "game.h"

/**
* Загружает изображение в текстуру для рендерера
* @param filepath Путь к изображению
* @param renderer Рендерер, на который эту текстуру можно будет отрисовать
* @return Возвращает текстуру, либо nullptr в случае ошибки.
*/
SDL_Texture *LoadTexture(const char *filepath, SDL_Renderer *renderer)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, filepath);

    if (!texture)
    {
        // TODO How to destroy window
        SDL_DestroyRenderer(renderer);
        raise_error(LOAD_TEXTURE_ERROR);
    }

    return texture;
}

/**
* Отобразить SDL_Texture на SDL_Renderer на координатах x, y, с масштабированием
* @param texture Текстура для отображения
* @param renderer Рендерер
* @param x Координаты
* @param y
* @param w Фактический размер при отрисовке
* @param h
*/
void RenderTextureByInput(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h)
{
    SDL_Rect dst;

    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;

    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

/**
* Отрисовать SDL_Texture на SDL_Renderer на координатах x, y, без масштабирования
* @param texture Текстура
* @param renderer Рендерер
* @param x Координаты
* @param y
*/
void RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y)
{
    int w, h;

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    RenderTextureByInput(texture, renderer, x, y, w, h);
}
