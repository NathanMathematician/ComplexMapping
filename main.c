#include <stdio.h>
#include <stdlib.h>

#include "graphing.h"

int main(int argc, char* argv[])
{
    printf("\n\nWelcome to ComplexMapping");
    
    SDL_Window *window = NULL;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "SDL Initialization error: %s\n", SDL_GetError());
        return -1;
    }
    
    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);

    if(NULL == window)
    {
        fprintf(stderr, "Window creation error: %s\n", SDL_GetError());
    }
    else
    {
        SDL_Delay(1000);
        SDL_DestroyWindow(window);
    }

    SDL_Quit();

    return 0;
}