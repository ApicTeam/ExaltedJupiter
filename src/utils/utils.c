#include "game.h"
#include "minilib.h"

char* mx_itoa(int value, char* str, int radix);

SDL_Texture *AnimateByFrames(t_frameanim *tFrameanim)
{
    /* Base Variables */
    int frame = (SDL_GetTicks() / tFrameanim->delayPerFrame) % tFrameanim->totalFrames;
    char *frame_str = calloc(50, sizeof(char));

    char *frame_count = calloc(10, sizeof(char));

    /* Main Logic */
    frame_str = strcat(frame_str, tFrameanim->frames_dir);
    frame_str = strcat(frame_str, mx_itoa(frame, frame_count, 10));
    frame_str = strcat(frame_str, ".png");

    /* Textures */
    SDL_Texture *Frame = LoadTexture(frame_str, tFrameanim->renderer);
    free(frame_str);
    free(frame_count);
    return Frame;
}

/**
 * Function make Texture for Sprite Sheet
 * @param texture Texture
 * @param textureRect Texture size width height and position x, y
 * @param frameRect Fame rect
 * @param frame_count Frame count
 * @return struct for SpriteSheet
 */
t_texture_ss LoadSpriteSheet(SDL_Texture *texture, SDL_Rect textureRect, SDL_Rect frameRect, int frame_count)
{
    t_texture_ss textureSs;

    textureSs.texture = texture;

    SDL_QueryTexture(texture, NULL, NULL, &frameRect.w, &frameRect.h);
    frameRect.w /= frame_count;

    textureSs.texSize = textureRect;
    textureSs.frame = frameRect;

    return textureSs;
}

char* mx_itoa(int value, char* str, int radix) {
    static char dig[] =
            "0123456789"
            "abcdefghijklmnopqrstuvwxyz";
    int n = 0, neg = 0;
    unsigned int v;
    char* p, *q;
    char c;
    if (radix == 10 && value < 0) {
        value = -value;
        neg = 1;
    }
    v = value;
    do {
        str[n++] = dig[v%radix];
        v /= radix;
    } while (v);
    if (neg)
        str[n++] = '-';
    str[n] = '\0';
    for (p = str, q = p + n/2; p != q; ++p, --q)
        c = *p, *p = *q, *q = c;
    return str;
}
