#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <complex.h>

#include "graphing.h"

int main(int argc, char* argv[])
{
    printf("\n\nWelcome to ComplexMapping\n\n");

    unsigned char continueComplexMapping = 1;

    while (continueComplexMapping == 1)
    {
        drawFunction();

        printf("\n\nDo you want to plot another function?\t1.Yes\t2.No");
        char *continueText = calloc(sizeof(char), INPUT_TEXT_MAX_CHAR_SIZE);
        readKeyboardInput(continueText);
        continueComplexMapping = strtod(continueText, NULL);
    }

    return 0;
}