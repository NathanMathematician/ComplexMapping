#ifndef GRAPHING_H

#define GRAPHING_H

/** Commentaries, tips, remarks, indications ============================ **/



/** Included header ===================================================== **/

#include "graphertool.h"

/** Macros ============================================================== **/



/** Preprocessor constants ============================================== **/



/** Global variables ==================================================== **/



/** Types, Structures and Aliases ======================================= **/



// Types //



// Structures //



/** Functions prototypes ================================================ **/

void drawFunction();

/** Functions =========================================================== **/

void drawFunction()
{
    char *windowTitle = "ComplexMapping";
    int windowWidth = 800;
    int windowHeight = 800;

    char *leftUpComplexText = malloc(INPUT_TEXT_MAX_CHAR_SIZE * sizeof(char));
    printf("What is the upper left corner complex for preimage bounds?\n");
    readKeyboardInput(leftUpComplexText);
    complex leftUpComplex;
    readComplexNumber(leftUpComplexText, &leftUpComplex);
    free(leftUpComplexText);

    char *rightDownComplexText = malloc(INPUT_TEXT_MAX_CHAR_SIZE * sizeof(char));
    printf("What is the lower right corner complex for preimage bounds?\n");
    readKeyboardInput(rightDownComplexText);
    complex rightDownComplex;
    readComplexNumber(rightDownComplexText, &rightDownComplex);
    free(rightDownComplexText);

    complex *imageList = malloc(sizeof(complex) * windowWidth * windowHeight);
    complexFunctionCalculation(&leftUpComplex, &rightDownComplex, windowWidth, windowHeight, imageList);

    //On demande avec ou sans damier
    printf("Visible checkerboard ?\t1.Yes\t2.No\n");
    char *checkerBoardText = malloc(INPUT_TEXT_MAX_CHAR_SIZE * sizeof(char));
    readKeyboardInput(checkerBoardText);
    double checkerBoardFlag = strtod(checkerBoardText, NULL);

    //On demande avec ou sans le module visible
    printf("Visible modulus ?\t1.Yes\t2.No\n");
    char *modulusText = malloc(INPUT_TEXT_MAX_CHAR_SIZE * sizeof(char));
    readKeyboardInput(modulusText);
    double modulusFlag = strtod(modulusText, NULL);

    initializeSDL();
    SDL_Window *fenetre = initializeAppWindow(windowTitle, &windowWidth, &windowHeight);
    SDL_Renderer *renderer = initializeWindowRender(fenetre);
    
    SDL_Color blackBrackgroundColor = {0, 0, 0, 255};
    colorRenderer(renderer, &blackBrackgroundColor);

    int heightCounter, widthCounter;
    for (heightCounter = 0 ; heightCounter < windowHeight ; heightCounter++)
    {
        for (widthCounter = 0 ; widthCounter < windowWidth ; widthCounter++)
        {
            drawPoint(renderer, imageList[widthCounter + heightCounter * windowWidth], widthCounter, heightCounter, checkerBoardFlag, modulusFlag);
        }
    }

    free(checkerBoardText);
    free(modulusText);
    free(imageList);

    printf("Drawing the function\nIt will be on screen until Esc is pressed on the keyboard.\n\n");

    SDL_RenderPresent(renderer);

    SDL_Event event;

    int continued = 1;
    while (continued != 0)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                continued = 0;
            }
        }
    }

    printf("\nQuitting SDL.");
    quitSDL(fenetre, renderer);
}


#endif // GRAPHING_H