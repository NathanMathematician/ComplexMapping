#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <complex.h>

#include "graphing.h"

int main(int argc, char* argv[])
{
    printf("\n\nWelcome to ComplexMapping\n\n");

//    complex complex1 = I*1;
//    complex complex2 = 2+I*2;
//
//    complex result = complex1 + complex2;
//
//    printf("\nresult value: %lf%+lfi", creal(result), cimag(result));
//
//    result = complex1 - complex2;
//
//    printf("\nresult value: %lf%+lfi", creal(result), cimag(result));
//
//    result = complex1 * complex2;
//
//    printf("\nresult value: %lf%+lfi", creal(result), cimag(result));
//
//    result = complex1 / complex2;
//
//    printf("\nresult value: %lf%+lfi", creal(result), cimag(result));
//
//    result = cpow(complex1, complex2);
//
//    printf("\nresult value: %lf%+lfi", creal(result), cimag(result));
//
//    complex *listComplex = malloc(sizeof(complex) * 2);
//    listComplex[0] = 1+I*2;
//    listComplex[1] = 5+I*5;
//
//    printf("\nlistComplex[0] value : %lf%+lfi", creal(listComplex[0]), cimag(listComplex[0]));
//    printf("\nlistComplex[1] value : %lf%+lfi", creal(listComplex[1]), cimag(listComplex[1]));
//
//    complex *complexTest1 = malloc(sizeof(complex));
//    *complexTest1 = -I*1;
//    double modulusVisibilityOff = 2;
//    double modulusVisibilityOn = 1;
//    
//    printf("\n\ncomplexTest1 value: %lf%+lfi", creal(*complexTest1), cimag(*complexTest1));
//    printf("\n\ncomplexTest1 argument value: %lf", carg(*complexTest1));
//    printf("\ncomplexTest1 modulus value: %lf", cabs(*complexTest1));
//    printf("\n\nPI/6 : %lf ; PI/4 : %lf ; PI/3 : %lf ; PI/2 : %lf ; ", M_PI/6, M_PI/4, M_PI/3, M_PI/2);

    SDL_Color *color1 = malloc(sizeof(SDL_Color));
    
//    complexToSDLcolor(complexTest1, &modulusVisibilityOff, color1);
//    printf("\ncolor1 value : (red=%u, green=%u, blue=%u, alpha=%u)", color1->r, color1->g, color1->b, color1->a);
//    
//    complexToSDLcolor(complexTest1, &modulusVisibilityOn, color1);
//    printf("\ncolor1 value : (red=%u, green=%u, blue=%u, alpha=%u)", color1->r, color1->g, color1->b, color1->a);
//
//    complexToSDLcolorCheckerBoard(complexTest1, &modulusVisibilityOff, color1);
//    printf("\ncolor1 value : (red=%u, green=%u, blue=%u, alpha=%u)", color1->r, color1->g, color1->b, color1->a);
//    
//    complexToSDLcolorCheckerBoard(complexTest1, &modulusVisibilityOn, color1);
//    printf("\ncolor1 value : (red=%u, green=%u, blue=%u, alpha=%u)", color1->r, color1->g, color1->b, color1->a);
    
    //OperatorComplex *listOperator = complexOperatorSupportedListGeneration()

//    char *complexRead = malloc(sizeof(char) * 10);
//    complexRead[0] = '2';
//    complexRead[1] = '.';
//    complexRead[2] = '5';
//    complexRead[3] = '+';
//    complexRead[4] = 'i';
//    complexRead[5] = '3';
//    complexRead[6] = '.';
//    complexRead[7] = '0';
//    complexRead[8] = '\0';
//
//    readComplexNumber(complexRead, complexTest1);
//    printf("\ncomplexTest1 value after lire : %lf%+lfi", creal(*complexTest1), cimag(*complexTest1));
//    printf("\ncomplexRead value : %s", complexRead);
//
//    const char *controlCharacters = "0123456789+-z";
//    char *stringToVerify = "cos";
//    char *verification = strpbrk(stringToVerify, controlCharacters);
//
//    printf("\n\nverification value : %s", verification);
//    printf("\nstringToVerify value : %s", stringToVerify);
//
//    //////
//
//    OperatorComplex *operatorList = malloc(sizeof(OperatorComplex) * OPERATOR_COMP_SUPPORTED_COUNT);
//    complexOperatorSupportedListGeneration(operatorList);
//
//    char *newToken = malloc(sizeof(char) * 2);
//    newToken[0] = '*';
//    newToken[1] = '\0';
//
//    char supportedListCounter;
//    for (supportedListCounter = 0 ; supportedListCounter < OPERATOR_COMP_SUPPORTED_COUNT ; supportedListCounter++)
//    {
//        if (strcmp(operatorList[supportedListCounter].operatorText, newToken) == 0)
//        {
//            break;
//        }
//    }
//    
//    printf("\nsupportedListCounter out of loop : %i", supportedListCounter);
//
//    //////////
//    char *stringCatResult = malloc(sizeof(char) * 100);
//    char *stringCatDest = malloc(sizeof(char) * 100);
//    stringCatDest[0] = '\0';
//
//    char *numberToCat = malloc(sizeof(char) * 5);
//    numberToCat[0] = '9';
//    numberToCat[1] = '+';
//    numberToCat[2] = 'i';
//    numberToCat[3] = '9';
//    numberToCat[4] = '\0';

//    stringCatResult = strcat(stringCatDest, numberToCat);
//    printf("\n\nstringCat first number :");
//    printf("%s", stringCatResult);
//
//    strcpy(stringCatDest, stringCatResult);
//    
//    stringCatResult = strcat(stringCatDest, " ");
//    printf("\nstringCat second number :");
//    printf("%s", stringCatResult);
//
//    strcpy(stringCatDest, stringCatResult);
//    
//    stringCatResult = strcat(stringCatDest, complexRead);
//    printf("\nstringCat second number :");
//    printf("%s", stringCatResult);

    //Same result shorter and less variable/////////////
//    strcat(stringCatDest, numberToCat);
//    printf("\n\nstringCat first number :");
//    printf("%s", stringCatDest);
//    
//    strcat(stringCatDest, " ");
//    //printf("\nstringCat second number :");
//    //printf("%s", stringCatDest);
//    
//    strcat(stringCatDest, complexRead);
//    printf("\nstringCat second number :");
//    printf("%s", stringCatDest);
//    ///////////////////////////////
//    printf("\n\n");
//    //To read the operatorStack do a strrchr of space character
//    //Then strncpy the left part of the operatorStack (to discard the last operator)
//    char *stringTest = malloc(sizeof(char) * 4);
//    stringTest[0] = '+';
//    stringTest[1] = ' ';
//    stringTest[2] = '*';
//    stringTest[3] = '\0';
//
//    char *stringTestDest = malloc(sizeof(char) * 5);
//    stringTestDest[0] = '\0';
//
//    char *testCharResult = strrchr(stringTest, ' ');
//    unsigned char sizeDiff = strlen(stringTest) - strlen(testCharResult);
//    printf("\ntestCharResult : %s", testCharResult);
//    printf("\nlength value : %u, %u and %u", strlen(stringTest), strlen(testCharResult), sizeDiff);
//    //stringTest = strncpy(stringTestDest, stringTest, sizeDiff + 1);
//    stringTest[sizeDiff] = 0;
//    printf("\nstringTest value : %s.", stringTest);

    ////////////////////////

    //char *strlenTest = malloc(sizeof(char) * 3);
    //strlenTest[0] = '\0';
    //printf("\n\nstrlenTest value : %u", strlen(strlenTest));

    ///////////////////////
//    char *functionExpression = calloc(INPUT_TEXT_MAX_CHAR_SIZE, sizeof(char));
//    char *parsedExpr = calloc(INPUT_TEXT_MAX_CHAR_SIZE, sizeof(char));
//    parsedExpr[0] = '\0';
//
//    printf("\n\nWhat is the function expression?\n");
//    lireSansSautDeLigneExpMath(functionExpression);
//
//    infixToReversePolish(functionExpression, parsedExpr);
//
//    printf("\n\nParsed expression :%s", parsedExpr);
//
//    

    ///////////////////////////////////
//
//    complex *preimageList = malloc(sizeof(complex) * 25);
//    complex *leftUp = malloc(sizeof(complex));
//    complex *rightDown = malloc(sizeof(complex));
//
//    *leftUp = -1 + I * 1;
//    *rightDown = 1 + I * -1;
//
//    complexPreImageListGeneration(leftUp, rightDown, 5, 5, preimageList);
//
//    int loopCounter = 0;
//    for (loopCounter = 0 ; loopCounter < 25 ; loopCounter++)
//    {
//        printf("\ncomplex n°%i :%lf+i%lf", loopCounter, creal(preimageList[loopCounter]), cimag(preimageList[loopCounter]));
//    }

    drawFunction();

    ///////////////////////////////////


    return 0;
}