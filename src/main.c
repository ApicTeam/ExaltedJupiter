#include "game.h"

int main(int argc, char *argv[])
{
    if (argc) {
        argv[0] = "aaa";
    }
    
    GameMain();
    return 0;
}
