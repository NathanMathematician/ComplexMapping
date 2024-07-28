#ifndef GRAPHERTOOL_H

#define GRAPHERTOOL_H

/** Commentaries, tips, remarks, indications ============================ **/



/** Included header ===================================================== **/

#include <SDL2/SDL.h>
#include "parsertool.h"

/** Macros ============================================================== **/



/** Preprocessor constants ============================================== **/



/** Global variables ==================================================== **/



/** Types, Structures and Aliases ======================================= **/



// Types //



// Structures //



/** Functions prototypes ================================================ **/

void initializeSDL();
void quitSDL(SDL_Window *window, SDL_Renderer *renderer);
SDL_Window *initializeAppWindow(const char *windowTitle, const int *windowWidth, const int *windowHeight);
SDL_Renderer *initializeWindowRender(SDL_Window *window);
void colorRenderer(SDL_Renderer *renderer, SDL_Color *color);
void complexToSDLcolor(const complex *number, const double *modulusVisibility, SDL_Color *complexColor);
void complexToSDLcolorCheckerBoard(const complex *number, const double *modulusVisibility, SDL_Color *complexColor);
void drawPoint(SDL_Renderer *renderer, complex number, int abscissa, int ordinate, double cherckerBoard, double modulusVisibility);

/** Functions =========================================================== **/

void initializeSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        //If there is an error, write it in the stderr file
        fprintf(stderr, "SDL_Init Error: %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);//Quit if there is an error
    }
}

void quitSDL(SDL_Window *window, SDL_Renderer *renderer)
{
    if (renderer != NULL)
    {
        SDL_DestroyRenderer(renderer);
    }

    if (window != NULL)
    {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}

SDL_Window *initializeAppWindow(const char *windowTitle, const int *windowWidth, const int *windowHeight)
{
    SDL_Window *window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, *windowWidth, *windowHeight, SDL_WINDOW_SHOWN);

    if (NULL == window)
    {
        //If there is an error, write it in the stderr file
        fprintf(stderr, "SDL_CreateWindow error: %s", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);//Quit if there is an error
    }
}

SDL_Renderer *initializeWindowRender(SDL_Window *window)
{
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        //If there is an error, write it in the stderr file
        fprintf(stderr, "SDL_CreateRenderer error: %s", SDL_GetError());
        if (renderer != NULL)
        {
            SDL_DestroyRenderer(renderer);
        }
        if (window != NULL)
        {
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
        exit(EXIT_FAILURE);//Quit if there is an error
    }
}

void colorRenderer(SDL_Renderer *renderer, SDL_Color *color)
{
    //On attribu au renderer la couleur voulu
    if (SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a) != 0)
    {
        //If there is an error, write it in the stderr file
        fprintf(stderr, "SDL_SetRenderDrawColor error: %s", SDL_GetError());
        if (renderer != NULL)
        {
            SDL_DestroyRenderer(renderer);
        }
        SDL_Quit();
        exit(EXIT_FAILURE);//Quit if there is an error
    }
    if(SDL_RenderClear(renderer) != 0)
    {
        //If there is an error, write it in the stderr file
        fprintf(stderr, "SDL_RenderClear error: %s", SDL_GetError());
        if (renderer != NULL)
        {
            SDL_DestroyRenderer(renderer);
        }
        SDL_Quit();
        exit(EXIT_FAILURE);//Quit if there is an error
    }

    //Actualize the renderer to show the wanted color
    SDL_RenderPresent(renderer);
}

void complexToSDLcolor(const complex *number, const double *modulusVisibility, SDL_Color *complexColor)
{
    complexColor->a = 255;//Alpha is always set to 255 (No transparency)


    double modulus = cabs(*number);
    double argument = carg(*number);

    double lightness = 0;

    if (*modulusVisibility < 2)
    {
        if (log(modulus) > 0)
        {
            lightness = 0.90 + 0.10 * fmod(log(modulus) / log(2), 1);
        }
        else
        {
            lightness = 1 - 0.10 * fmod((0 - log(modulus)) / log(2), 1);
        }
    }
    else
    {
        lightness = (1000+pow(modulus, 0.1)) * pow(pow(modulus, 0.1) + 1001, -1);
    }

//    double lightness = pow(modulus, 0.1) * pow(pow(modulus, 0.1) + 1, -1);
//    double lightness = (2 / M_PI) * atan(modulus);
//    double lightness = fmod(log(modulus) / log(2), 1);

    double hue = 0;
    if (argument >= 0)
    {
        hue = argument / ( M_PI / 3 );
    }
    else
    {
        hue = (2 * M_PI + argument) / (M_PI / 3);
    }

    double coloration = lightness * ( 1 - fabs(fmod(hue, 2) - 1) );

    if (0 <= hue && hue < 1)
    {
        complexColor->r = floor(lightness * 255);
        complexColor->g = floor(coloration * 255);
        complexColor->b = floor(0 * 255);
    }
    else if (1 <= hue && hue < 2)
    {
        complexColor->r = floor(coloration * 255);
        complexColor->g = floor(lightness * 255);
        complexColor->b = floor(0 * 255);
    }
    else if (2 <= hue && hue < 3)
    {
        complexColor->r = floor(0 * 255);
        complexColor->g = floor(lightness * 255);
        complexColor->b = floor(coloration * 255);
    }
    else if (3 <= hue && hue < 4)
    {
        complexColor->r = floor(0 * 255);
        complexColor->g = floor(coloration * 255);
        complexColor->b = floor(lightness * 255);
    }
    else if (4 <= hue && hue < 5)
    {
        complexColor->r = floor(coloration * 255);
        complexColor->g = floor(0 * 255);
        complexColor->b = floor(lightness * 255);
    }
    else
    {
        complexColor->r = floor(lightness * 255);
        complexColor->g = floor(0 * 255);
        complexColor->b = floor(coloration * 255);
    }
}

void complexToSDLcolorCheckerBoard(const complex *number, const double *modulusVisibility, SDL_Color *complexColor)
{
    complexColor->a = 255;//Alpha is always set to 255 (No transparency)

    double modulus = cabs(*number);
    double argument = carg(*number);

    double lightness = 0;

    if (*modulusVisibility < 2)
    {
        if (log(modulus) > 0)
        {
            lightness = 0.90 + 0.10 * fmod(log(modulus) / log(2), 1);
        }
        else
        {
            lightness = 1 - 0.10 * fmod((0 - log(modulus)) / log(2), 1);
        }
    }
    else
    {
        lightness = (1000+pow(modulus, 0.1)) * pow(pow(modulus, 0.1) + 1001, -1);
    }
    
//    double lightness = pow(module, 0.1) * pow(pow(module, 0.1) + 1, -1);
//    double lightness = (2 / M_PI) * atan(module);
//    double lightness = fmod(log(module) / log(2), 1);
//    double lightness = 0.90 + 0.10 * fmod(log(module) / log(2), 1);

    double hue = 0;
    if (argument >= 0)
    {
        hue = argument / ( M_PI / 3 );
    }
    else
    {
        hue = (2 * M_PI + argument) / (M_PI / 3);
    }
    double coloration = lightness * ( 1 - fabs(fmod(hue, 2) - 1) );

    double checkerBoardSize = 1;
    double cherckerBoardfmod0 = 0;
    double cherckerBoardfmod1 = checkerBoardSize / 2;
    double cherckerBoardfmod2 = checkerBoardSize;
    double cherckerBoardfmodm1 = 0 - checkerBoardSize / 2;
    double cherckerBoardfmodm2 = 0 - checkerBoardSize;
    int checkerBoardIntensity = 30;

    double realPartMod = fmod(creal(*number), checkerBoardSize);
    double imagPartMod = fmod(cimag(*number), checkerBoardSize);

    if (0 <= hue && hue < 1)
    {
        complexColor->r = floor(lightness * 255);
        complexColor->g = floor(coloration * 255);
        complexColor->b = floor(0 * 255);

        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
    }
    else if (1 <= hue && hue < 2)
    {
        complexColor->r = floor(coloration * 255);
        complexColor->g = floor(lightness * 255);
        complexColor->b = floor(0 * 255);

        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
    }
    else if (2 <= hue && hue < 3)
    {
        complexColor->r = floor(0 * 255);
        complexColor->g = floor(lightness * 255);
        complexColor->b = floor(coloration * 255);

        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->g = complexColor->g - checkerBoardIntensity;
            }
        }
    }
    else if (3 <= hue && hue < 4)
    {
        complexColor->r = floor(0 * 255);
        complexColor->g = floor(coloration * 255);
        complexColor->b = floor(lightness * 255);

        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
    }
    else if (4 <= hue && hue < 5)
    {
        complexColor->r = floor(coloration * 255);
        complexColor->g = floor(0 * 255);
        complexColor->b = floor(lightness * 255);

        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->b = complexColor->b - checkerBoardIntensity;
            }
        }
    }
    else
    {
        complexColor->r = floor(lightness * 255);
        complexColor->g = floor(0 * 255);
        complexColor->b = floor(coloration * 255);

        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmod0 <= imagPartMod && imagPartMod < cherckerBoardfmod1)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmod1 <= imagPartMod && imagPartMod < cherckerBoardfmod2)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm1 <= realPartMod && realPartMod < cherckerBoardfmod0)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmodm2 <= realPartMod && realPartMod < cherckerBoardfmodm1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod0 <= realPartMod && realPartMod < cherckerBoardfmod1)
        {
            if (cherckerBoardfmodm2 <= imagPartMod && imagPartMod < cherckerBoardfmodm1)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
        if (cherckerBoardfmod1 <= realPartMod && realPartMod < cherckerBoardfmod2)
        {
            if (cherckerBoardfmodm1 <= imagPartMod && imagPartMod < cherckerBoardfmod0)
            {
                complexColor->r = complexColor->r - checkerBoardIntensity;
            }
        }
    }
}

void drawPoint(SDL_Renderer *renderer, complex number, int abscissa, int ordinate, double cherckerBoard, double modulusVisibility)
{
    //Calculate the point color according to the checkerBoard flag value
    if (cherckerBoard < 2)
    {
        SDL_Color *complexColor = malloc(sizeof(SDL_Color));
        complexToSDLcolorCheckerBoard(&number, &modulusVisibility, complexColor);

        //Setting the color to draw
        SDL_SetRenderDrawColor(renderer, complexColor->r, complexColor->g, complexColor->b, complexColor->a);
        //Draw the pixel with the setted color
        SDL_RenderDrawPoint(renderer, abscissa, ordinate);
    }
    else
    {
        SDL_Color *complexColor = malloc(sizeof(SDL_Color));
        complexToSDLcolor(&number, &modulusVisibility, complexColor);

        //Setting the color to draw
        SDL_SetRenderDrawColor(renderer, complexColor->r, complexColor->g, complexColor->b, complexColor->a);
        //Draw the pixel with the setted color
        SDL_RenderDrawPoint(renderer, abscissa, ordinate);
    }
}

#endif // GRAPHERTOOL_H