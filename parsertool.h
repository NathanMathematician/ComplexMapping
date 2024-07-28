#ifndef PARSERTOOL_H

#define PARSERTOOL_H

/** Commentaries, tips, remarks, indications ============================ **/



/** Included header ===================================================== **/

#include <string.h>
#include <math.h>
#include <complex.h>

/** Macros ============================================================== **/



/** Preprocessor constants ============================================== **/

// Code for operators associativity
#define ASSOCIATIVITY_NULL              0
#define ASSOCIATIVITY_LEFT              1
#define ASSOCIATIVITY_RIGHT             2

// Code for operators unitarity or binarity
#define OPERATOR_BINARY 0
#define OPERATOR_UNARY 1

// Count for number of supported operator
#define OPERATOR_REAL_SUPPORTED_COUNT   8
#define OPERATOR_COMP_SUPPORTED_COUNT   28
#define OPERATOR_COMP_FUNCTIONS_START_RANGE 7

#define INPUT_TEXT_MAX_CHAR_SIZE        100
#define INPUT_TEXT_MAX_OPERATOR         33
#define NUMBER_AS_TEXT_MAX_CHAR         30
#define STRLEN_FOR_FUNCTIONS            3

/** Global variables ==================================================== **/



/** Types, Structures and Aliases ======================================= **/

// Aliases //

typedef double realNumber;
typedef double complex complexNumber;

// Types //



// Structures //

typedef struct OperatorReal OperatorReal;
struct OperatorReal
{
    char* operatorText;
    unsigned char precedence;
    unsigned char associativity;
    unsigned char unaryORbinary;
    void (*operationRealEvaluation)(const realNumber *realLeft, const realNumber *realRight, realNumber *result);
};

typedef struct OperatorComplex OperatorComplex;
struct OperatorComplex
{
    char* operatorText;
    unsigned char precedence;
    unsigned char associativity;
    unsigned char unaryORbinary;
    void (*operationComplexEvaluation)(const complex *complexLeft, const complex *complexRight, complex *result);
};

/** Functions prototypes ================================================ **/

////////////////////////////////////////////////////////
// Prototypes for real operators evaluation functions //
////////////////////////////////////////////////////////

void realAddition(const realNumber *realLeft, const realNumber *realRight, realNumber *result);
void realSubtraction(const realNumber *realLeft, const realNumber *realRight, realNumber *result);
void realMultiplication(const realNumber *realLeft, const realNumber *realRight, realNumber *result);
void realDivision(const realNumber *realLeft, const realNumber *realRight, realNumber *result);
void realModulo(const realNumber *realLeft, const realNumber *realRight, realNumber *result);
void realPower(const realNumber *realLeft, const realNumber *realRight, realNumber *result);

void realOperatorSupportedListGeneration(OperatorReal *realOperatorList);

///////////////////////////////////////////////////////////////////
// Function prototype for complex operators evaluation functions //
///////////////////////////////////////////////////////////////////

int readKeyboardInput(char *chaine);
void readComplexNumber(char* complexInputText, complex *number);

void complexAddition(const complex *complexLeft, const complex *complexRight, complex *result);
void complexSubtraction(const complex *complexLeft, const complex *complexRight, complex *result);
void complexMultiplication(const complex *complexLeft, const complex *complexRight, complex *result);
void complexDivision(const complex *complexLeft, const complex *complexRight, complex *result);
void complexModulo(const complex *complexLeft, const complex *complexRight, complex *result);
void complexPower(const complex *complexLeft, const complex *complexRight, complex *result);

void complexAbs(const complex *number, const complex *voidNumber,complex *result);
void complexArg(const complex *number, const complex *voidNumber,complex *result);
void complexImag(const complex *number, const complex *voidNumber,complex *result);
void complexReal(const complex *number, const complex *voidNumber,complex *result);
void complexConj(const complex *number, const complex *voidNumber,complex *result);
void complexProj(const complex *number, const complex *voidNumber,complex *result);

void complexExp(const complex *number, const complex *voidNumber,complex *result);
void complexLog(const complex *number, const complex *voidNumber,complex *result);
void complexSqrt(const complex *number, const complex *voidNumber,complex *result);

void complexSin(const complex *number, const complex *voidNumber,complex *result);
void complexCos(const complex *number, const complex *voidNumber,complex *result);
void complexTan(const complex *number, const complex *voidNumber,complex *result);
void complexAsin(const complex *number, const complex *voidNumber,complex *result);
void complexAcos(const complex *number, const complex *voidNumber,complex *result);
void complexAtan(const complex *number, const complex *voidNumber,complex *result);

void complexSinh(const complex *number, const complex *voidNumber,complex *result);
void complexCosh(const complex *number, const complex *voidNumber,complex *result);
void complexTanh(const complex *number, const complex *voidNumber,complex *result);
void complexAsinh(const complex *number, const complex *voidNumber,complex *result);
void complexAcosh(const complex *number, const complex *voidNumber,complex *result);
void complexAtanh(const complex *number, const complex *voidNumber,complex *result);

void complexOperatorSupportedListGeneration(OperatorComplex *realOperatorList);

/////////////////////////////////////////////
// Prototypes for reading complex function //
/////////////////////////////////////////////

void complexToChar(const complex *number, char *numberAsText);
void infixToReversePolish(char *expressionComplex, char *parsedExpression);
void literalExpressionToEvaluationExpression(char *literalExpression, const complex *value, char *evaluationExpression);
void evaluateExpressionCalculation(char *evaluationExpression, complex *result);
void complexPreImageListGeneration(const complex *leftUp, const complex *rightDown, int windowWidth, int windowHeight, complex *preImageList);
void complexFunctionCalculation(complex *leftUp, complex *rightDown, int windowWidth, int windowHeight, complex *imageList);

/** Functions =========================================================== **/

/////////////////////////////////////////////////////////////////
// Function definition for real operators evaluation functions //
/////////////////////////////////////////////////////////////////

void realAddition(const realNumber *realLeft, const realNumber *realRight, realNumber *result)
{
    *result = *realLeft + *realRight;
}

void realSubtraction(const realNumber *realLeft, const realNumber *realRight, realNumber *result)
{
    *result = *realLeft - *realRight;
}

void realMultiplication(const realNumber *realLeft, const realNumber *realRight, realNumber *result)
{
    *result = *realLeft * *realRight;
}

void realDivision(const realNumber *realLeft, const realNumber *realRight, realNumber *result)
{
    *result = *realLeft / *realRight;
}

void realModulo(const realNumber *realLeft, const realNumber *realRight, realNumber *result)
{
    *result = fmod(*realLeft, *realRight);
}

void realPower(const realNumber *realLeft, const realNumber *realRight, realNumber *result)
{
    *result = pow(*realLeft, *realRight);
}

void realOperatorSupportedListGeneration(OperatorReal *realOperatorList)
{
    realOperatorList = malloc(sizeof(OperatorReal) * OPERATOR_REAL_SUPPORTED_COUNT);

    if (realOperatorList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    realOperatorList[0].operatorText = "(";
    realOperatorList[0].precedence = 0;
    realOperatorList[0].associativity = ASSOCIATIVITY_NULL;
    realOperatorList[0].unaryORbinary = OPERATOR_BINARY;
    realOperatorList[0].operationRealEvaluation = NULL;

    realOperatorList[1].operatorText = ")";
    realOperatorList[1].precedence = 0;
    realOperatorList[1].associativity = ASSOCIATIVITY_NULL;
    realOperatorList[1].unaryORbinary = OPERATOR_BINARY;
    realOperatorList[1].operationRealEvaluation = NULL;

    realOperatorList[2].operatorText = "+";
    realOperatorList[2].precedence = 5;
    realOperatorList[2].associativity = ASSOCIATIVITY_LEFT;
    realOperatorList[2].unaryORbinary = OPERATOR_BINARY;
    realOperatorList[2].operationRealEvaluation = realAddition;

    realOperatorList[3].operatorText = "-";
    realOperatorList[3].precedence = 5;
    realOperatorList[3].associativity = ASSOCIATIVITY_LEFT;
    realOperatorList[3].unaryORbinary = OPERATOR_BINARY;
    realOperatorList[3].operationRealEvaluation = realSubtraction;

    realOperatorList[4].operatorText = "*";
    realOperatorList[4].precedence = 8;
    realOperatorList[4].associativity = ASSOCIATIVITY_LEFT;
    realOperatorList[4].unaryORbinary = OPERATOR_BINARY;
    realOperatorList[4].operationRealEvaluation = realMultiplication;

    realOperatorList[5].operatorText = "/";
    realOperatorList[5].precedence = 8;
    realOperatorList[5].associativity = ASSOCIATIVITY_LEFT;
    realOperatorList[5].unaryORbinary = OPERATOR_BINARY;
    realOperatorList[5].operationRealEvaluation = realDivision;

    realOperatorList[6].operatorText = "%";
    realOperatorList[6].precedence = 8;
    realOperatorList[6].associativity = ASSOCIATIVITY_LEFT;
    realOperatorList[6].unaryORbinary = OPERATOR_BINARY;
    realOperatorList[6].operationRealEvaluation = realModulo;

    realOperatorList[7].operatorText = "^";
    realOperatorList[7].precedence = 9;
    realOperatorList[7].associativity = ASSOCIATIVITY_RIGHT;
    realOperatorList[7].unaryORbinary = OPERATOR_BINARY;
    realOperatorList[7].operationRealEvaluation = realPower;
}


/////////////////////////////////////////////////////////////////
// Function definition for real operators evaluation functions //
/////////////////////////////////////////////////////////////////

void emptyBuffer()
{
    char c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int readKeyboardInput(char *inputChain)
{
    char *inputPosition = NULL;

    //Reading the inputed text
    if (fgets(inputChain, INPUT_TEXT_MAX_CHAR_SIZE, stdin) != NULL)
    {
        //Searching for the next line special character
        inputPosition = strchr(inputChain, '\n');
        
        if (inputPosition != NULL)
        {
            //If found, replace with the null terminated special character
            *inputPosition = '\0';
        }
        else
        {
            //If not found, empty the buffer
            emptyBuffer(); // On vide le buffer de ce qu'il reste eventuellement dedans
        }
        
        return EXIT_SUCCESS;
    }
    else
    {
        //Empty the buffer for security after if an error happens
        emptyBuffer();

        return EXIT_FAILURE;
    }
}

void readComplexNumber(char* complexInputText, complex *number)
{
    //On initialise le pointeur qui permettra de lire la partie imaginaire
    char *imaginaryPartPointer = NULL;

    //On définit le séparateur qui est 'i'
    const char *chiffres = "0123456789-";

    //On récupère la partie réelle dans le NombreComplexe
    double realPart = strtod(complexInputText, &imaginaryPartPointer);

    //On récupère la partie imaginaire
    complexInputText = strpbrk(imaginaryPartPointer, chiffres);

    //On récupère la partie imaginaire dans le NombreComplexe
    double imagPart = strtod(complexInputText, NULL);

    *number = realPart + I * imagPart;
}

//Classic operations

void complexAddition(const complex *complexLeft, const complex *complexRight, complex *result)
{
    *result = *complexLeft + *complexRight;
}

void complexSubtraction(const complex *complexLeft, const complex *complexRight, complex *result)
{
    *result = *complexLeft - *complexRight;
}

void complexMultiplication(const complex *complexLeft, const complex *complexRight, complex *result)
{
    *result = *complexLeft * *complexRight;
}

void complexDivision(const complex *complexLeft, const complex *complexRight, complex *result)
{
    *result = *complexLeft / *complexRight;
}

//void complexModulo(const complex *complexLeft, const complex *complexRight, complex *result)
//{
//    //To see later
//}

void complexPower(const complex *complexLeft, const complex *complexRight, complex *result)
{
    *result = cpow(*complexLeft, *complexRight);
}

//Basic complex functions

void complexAbs(const complex *number, const complex *voidNumber,complex *result)
{
    *result = cabs(*number);
}

void complexArg(const complex *number, const complex *voidNumber,complex *result)
{
    *result = carg(*number);
}

void complexImag(const complex *number, const complex *voidNumber,complex *result)
{
    *result = cimag(*number);
}

void complexReal(const complex *number, const complex *voidNumber,complex *result)
{
    *result = creal(*number);
}

void complexConj(const complex *number, const complex *voidNumber,complex *result)
{
    *result = conj(*number);
}

void complexProj(const complex *number, const complex *voidNumber,complex *result)
{
    *result = cproj(*number);
}

//Exponentiation functions

void complexExp(const complex *number, const complex *voidNumber,complex *result)
{
    *result = cexp(*number);
}

void complexLog(const complex *number, const complex *voidNumber,complex *result)
{
    *result = clog(*number);
}

void complexSqrt(const complex *number, const complex *voidNumber,complex *result)
{
    *result = csqrt(*number);
}

//Trigonometric functions

void complexSin(const complex *number, const complex *voidNumber,complex *result)
{
    *result = csin(*number);
}

void complexCos(const complex *number, const complex *voidNumber,complex *result)
{
    *result = ccos(*number);
}

void complexTan(const complex *number, const complex *voidNumber,complex *result)
{
    *result = ctan(*number);
}

void complexAsin(const complex *number, const complex *voidNumber,complex *result)
{
    *result = casin(*number);
}

void complexAcos(const complex *number, const complex *voidNumber,complex *result)
{
    *result = cacos(*number);
}

void complexAtan(const complex *number, const complex *voidNumber,complex *result)
{
    *result = catan(*number);
}

//Hyperbolic functions

void complexSinh(const complex *number, const complex *voidNumber,complex *result)
{
    *result = csinh(*number);
}

void complexCosh(const complex *number, const complex *voidNumber,complex *result)
{
    *result = ccosh(*number);
}

void complexTanh(const complex *number, const complex *voidNumber,complex *result)
{
    *result = ctanh(*number);
}

void complexAsinh(const complex *number, const complex *voidNumber,complex *result)
{
    *result = casinh(*number);
}

void complexAcosh(const complex *number, const complex *voidNumber,complex *result)
{
    *result = cacosh(*number);
}

void complexAtanh(const complex *number, const complex *voidNumber,complex *result)
{
    *result = catanh(*number);
}


void complexOperatorSupportedListGeneration(OperatorComplex *complexOperatorList)
{
    if (complexOperatorList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    unsigned char counter = 0;

    //Classic operations

    complexOperatorList[counter].operatorText = "(";
    complexOperatorList[counter].precedence = 0;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_BINARY;
    complexOperatorList[counter].operationComplexEvaluation = NULL;

    counter++;

    complexOperatorList[counter].operatorText = ")";
    complexOperatorList[counter].precedence = 0;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_BINARY;
    complexOperatorList[counter].operationComplexEvaluation = NULL;

    counter++;

    complexOperatorList[counter].operatorText = "+";
    complexOperatorList[counter].precedence = 1;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_LEFT;
    complexOperatorList[counter].unaryORbinary = OPERATOR_BINARY;
    complexOperatorList[counter].operationComplexEvaluation = complexAddition;

    counter++;

    complexOperatorList[counter].operatorText = "-";
    complexOperatorList[counter].precedence = 1;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_LEFT;
    complexOperatorList[counter].unaryORbinary = OPERATOR_BINARY;
    complexOperatorList[counter].operationComplexEvaluation = complexSubtraction;

    counter++;

    complexOperatorList[counter].operatorText = "*";
    complexOperatorList[counter].precedence = 2;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_LEFT;
    complexOperatorList[counter].unaryORbinary = OPERATOR_BINARY;
    complexOperatorList[counter].operationComplexEvaluation = complexMultiplication;

    counter++;

    complexOperatorList[counter].operatorText = "/";
    complexOperatorList[counter].precedence = 2;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_LEFT;
    complexOperatorList[counter].unaryORbinary = OPERATOR_BINARY;
    complexOperatorList[counter].operationComplexEvaluation = complexDivision;

    counter++;

    complexOperatorList[counter].operatorText = "^";
    complexOperatorList[counter].precedence = 4;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_RIGHT;
    complexOperatorList[counter].unaryORbinary = OPERATOR_BINARY;
    complexOperatorList[counter].operationComplexEvaluation = complexPower;

    counter++;

    //Basic complex functions

    complexOperatorList[counter].operatorText = "fabs";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexAbs;

    counter++;

    complexOperatorList[counter].operatorText = "farg";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexArg;

    counter++;

    complexOperatorList[counter].operatorText = "fimag";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexImag;

    counter++;

    complexOperatorList[counter].operatorText = "freal";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexReal;

    counter++;

    complexOperatorList[counter].operatorText = "fconj";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexConj;

    counter++;

    complexOperatorList[counter].operatorText = "fproj";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexProj;

    counter++;

    //Exponentiation functions

    complexOperatorList[counter].operatorText = "fexp";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexExp;

    counter++;

    complexOperatorList[counter].operatorText = "flog";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexLog;

    counter++;

    complexOperatorList[counter].operatorText = "fsqrt";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexSqrt;

    counter++;

    //Trigonometric functions

    complexOperatorList[counter].operatorText = "fsin";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexSin;

    counter++;

    complexOperatorList[counter].operatorText = "fcos";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexCos;

    counter++;

    complexOperatorList[counter].operatorText = "ftan";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexTan;

    counter++;

    complexOperatorList[counter].operatorText = "fasin";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexAsin;

    counter++;

    complexOperatorList[counter].operatorText = "facos";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexAcos;

    counter++;

    complexOperatorList[counter].operatorText = "fatan";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexAtan;

    counter++;

    //Hyperbolic functions

    complexOperatorList[counter].operatorText = "fsinh";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexSinh;

    counter++;

    complexOperatorList[counter].operatorText = "fcosh";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexCosh;

    counter++;

    complexOperatorList[counter].operatorText = "ftanh";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexTanh;

    counter++;

    complexOperatorList[counter].operatorText = "fasinh";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexAsinh;

    counter++;

    complexOperatorList[counter].operatorText = "facosh";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexAcosh;

    counter++;

    complexOperatorList[counter].operatorText = "fatanh";
    complexOperatorList[counter].precedence = 8;
    complexOperatorList[counter].associativity = ASSOCIATIVITY_NULL;
    complexOperatorList[counter].unaryORbinary = OPERATOR_UNARY;
    complexOperatorList[counter].operationComplexEvaluation = complexAtanh;
}

////////////////////////////////////////////
// Functions for reading complex function //
////////////////////////////////////////////

void complexToChar(const complex *number, char *numberAsText)
{
    sprintf(numberAsText, "%lf+i%lf", creal(*number), cimag(*number));
}

void infixToReversePolish(char *expressionComplex, char *parsedExpression)
{
    //Parsing done with shunting yard algorithm

    //Initialize the supported operator
    OperatorComplex *supportedOperatorList = malloc(sizeof(OperatorComplex) * OPERATOR_COMP_SUPPORTED_COUNT);
    complexOperatorSupportedListGeneration(supportedOperatorList);
    char supportedListCounter = 0;

    //Initialize operatorStack
    char *operatorStack = calloc(INPUT_TEXT_MAX_OPERATOR, sizeof(char));
    operatorStack[0] = '\0';
    
    //Initialize verification pointer to help identify numbers and other tokens in the expression
    char *verificationPointer = calloc(INPUT_TEXT_MAX_OPERATOR, sizeof(char));
    verificationPointer[0] = '\0';
    char verificationPointerCount = 0;
    char reducedSize = 0;

    //Define the separator (There's only one, it's a space character)
    const char *SEPARATORS = " ";
    //Define the control characters to identify numbers and operators
    const char *CONTROLCHARACTERSnumbers = "0123456789z";
    const char *CONTROLCHARACTERSoperators = "+-*/^";

    //Initialize the token catcher
    char *newToken = strtok(expressionComplex, SEPARATORS);
    char *newTokenCopy = malloc(sizeof(char) * strlen(newToken));

    while (newToken != NULL)
    {
        if (strpbrk(newToken, CONTROLCHARACTERSnumbers) != NULL)
        {
            //If newToken is a number, put it into the output queue (parsedExpression)
            //OR if newToken is 'z', replace it with the antecedent and put it into the output queue (parsedExpression)
            strcat(parsedExpression, newToken);
            strcat(parsedExpression, " ");
        }
        else if (strpbrk(newToken, CONTROLCHARACTERSoperators) != NULL)
        {
            //If newToken is an operator ope1

            //For loop to know which operator newToken is, the operator position in the supported is given with resulting supportedListCounter value after the for loop
            for (supportedListCounter = 0 ; supportedListCounter < OPERATOR_COMP_SUPPORTED_COUNT ; supportedListCounter++)
            {
                if (strcmp(supportedOperatorList[supportedListCounter].operatorText, newToken) == 0)
                {
                    break;
                }
            }

            while (strlen(operatorStack) != 0)
            {
                //While there is an operator ope2 which is not a left parenthesis AND
                //ope2 has greater precedence than ope1 OR (ope1 and ope2 has same precedence AND ope1 is left-associative)
                //Pop ope2 from the operatorStack into the output queue (parsedExpression)
                verificationPointer = strrchr(operatorStack, ' ');

                if (verificationPointer == NULL)
                {
                    //If verificationPointer is NULL,
                    //there is only one last operator in operatorStack
                    verificationPointer = operatorStack;

                    if (strchr(verificationPointer, '(') != NULL)
                    {
                        //If ope2 is a left parenthesis, jump out of the while loop
                        break;
                    }
                    
                    //Identify the operator in verificationPointer
                    for (verificationPointerCount = 0 ; verificationPointerCount < OPERATOR_COMP_SUPPORTED_COUNT ; verificationPointerCount++)
                    {
                        if (strcmp(supportedOperatorList[verificationPointerCount].operatorText, verificationPointer) == 0)
                        {
                            //When the corresponding operator is found jump out of the for loop
                            break;
                        }
                    }

                    if (supportedOperatorList[supportedListCounter].precedence < supportedOperatorList[verificationPointerCount].precedence || (supportedOperatorList[supportedListCounter].precedence == supportedOperatorList[verificationPointerCount].precedence && supportedOperatorList[supportedListCounter].associativity == ASSOCIATIVITY_LEFT))
                    {
                        //If the condition is met put ope2 in the parsedExpression
                        strcat(parsedExpression, verificationPointer);
                        strcat(parsedExpression, " ");

                        //Deleting the operator taken from the operatorStack
                        operatorStack[0] = '\0';
                    }
                    else
                    {
                        //If condition is not met put ope2 back in the operatorStack
                        //and jump out of the while loop
                        break;
                    }
                }
                else
                {
                    //If the verificationPointer is not NULL,
                    //Place it on the next character to read the operator without the space character
                    verificationPointer++;

                    if (strchr(verificationPointer, '(') != NULL)
                    {
                        //If ope2 is a left parenthesis, jump out of the while loop
                        break;
                    }

                    //Identify the operator in verificationPointer
                    for (verificationPointerCount = 0 ; verificationPointerCount < OPERATOR_COMP_SUPPORTED_COUNT ; verificationPointerCount++)
                    {
                        if (strcmp(supportedOperatorList[verificationPointerCount].operatorText, verificationPointer) == 0)
                        {
                            //When the corresponding operator is found jump out of the for loop
                            break;
                        }
                    }

                    if (supportedOperatorList[supportedListCounter].precedence < supportedOperatorList[verificationPointerCount].precedence || (supportedOperatorList[supportedListCounter].precedence == supportedOperatorList[verificationPointerCount].precedence && supportedOperatorList[supportedListCounter].associativity == ASSOCIATIVITY_LEFT))
                    {
                        //If the condition is met put ope2 in the parsedExpression
                        strcat(parsedExpression, verificationPointer);
                        strcat(parsedExpression, " ");

                        //Deleting the operator taken from the operatorStack
                        operatorStack[strlen(operatorStack) - strlen(verificationPointer) - 1] = '\0';
                    }
                    else
                    {
                        //If condition is not met put ope2 back in the operatorStack
                        //and jump out of the while loop
                        break;
                    }
                }
            }

            //Push ope1 onto the operatorStack
            if (strlen(operatorStack) != 0)
            {
                strcat(operatorStack, " ");
                strcat(operatorStack, newToken);
            }
            else
            {
                strcat(operatorStack, newToken);
            }
        }
        else if (strchr(newToken, ')') != NULL)
        {
            //If newToken is a right parenthesis ")"

            while (strlen(operatorStack) != 0)
            {
                //While the operator at the top of the operatorStack is not a left parenthesis
                //Pop the operator from the operatorStack into the output queue (parsedExpression)

                verificationPointer = strrchr(operatorStack, ' ');

                if (verificationPointer == NULL)
                {
                    //If verificationPointer is NULL,
                    //there is only one last operator in operatorStack
                    verificationPointer = operatorStack;
                    
                    if (strcmp(verificationPointer, "(") == 0)
                    {
                        //If it's a left parenthesis, pop it from the operatorStack and discard it
                        //Then jump out of the while loop

                        //Deleting the operator taken from the operatorStack
                        operatorStack[0] = '\0';

                        break;
                    }

                    strcat(parsedExpression, verificationPointer);
                    strcat(parsedExpression, " ");
                    
                    //Deleting the operator taken from the operatorStack
                    operatorStack[0] = '\0';
                }
                else
                {
                    //If the verificationPointer is not NULL,
                    //Place it on the next character to read the operator without the space character
                    verificationPointer++;
                    
                    if (strcmp(verificationPointer, "(") == 0)
                    {
                        //If it's a left parenthesis, pop it from the operatorStack and discard it
                        //Then jump out of the while loop

                        //Deleting the operator taken from the operatorStack
                        operatorStack[strlen(operatorStack) - strlen(verificationPointer) - 1] = '\0';

                        break;
                    }

                    strcat(parsedExpression, verificationPointer);
                    strcat(parsedExpression, " ");

                    //Deleting the operator taken from the operatorStack
                    operatorStack[strlen(operatorStack) - strlen(verificationPointer) - 1] = '\0';
                }
            }

            //if (strlen(operatorStack) == 0)
            //{
            //    printf("\n\nError : There are mismatched parentheses. Exiting.");
            //    exit(EXIT_FAILURE);
            //}

            //Pop the left parenthesis from the operatorStack and discard it
            
            if (strlen(operatorStack) != 0)
            {
                verificationPointer = strrchr(operatorStack, ' ');

                if (verificationPointer == NULL)
                {
                    //If verificationPointer is NULL,
                    //there is only one last operator in operatorStack
                    verificationPointer = operatorStack;
                    
                    if (strlen(verificationPointer) >= STRLEN_FOR_FUNCTIONS)
                    {
                        //If there is a function at the top of the operatorStack
                        //Pop the function from the operatorStack into the output queue (parsedExpression)
                        strcat(parsedExpression, verificationPointer);
                        strcat(parsedExpression, " ");

                        //Deleting the operator taken from the operatorStack
                        operatorStack[0] = '\0';
                    }
                }
                else
                {
                    //If the verificationPointer is not NULL,
                    //Place it on the next character to read the operator without the space character
                    verificationPointer++;
                    
                    if (strlen(verificationPointer) >= STRLEN_FOR_FUNCTIONS)
                    {
                        //If there is a function at the top of the operatorStack
                        //Pop the function from the operatorStack into the output queue (parsedExpression)
                        strcat(parsedExpression, verificationPointer);
                        strcat(parsedExpression, " ");

                        //Deleting the operator taken from the operatorStack
                        operatorStack[strlen(operatorStack) - strlen(verificationPointer) - 1] = '\0';
                        
                    }
                }
            }
            else
            {
                //If the operatorStack is empty,
                //set verificationPointer to NULL
                verificationPointer = NULL;
            }
        }
        else
        {
            //If newToken is a function, push it onto the operatorStack
            //OR if newToken is a left parenthesis "(", push it onto the operatorStack
            if (newToken[0] == '(')
            {
                if (strlen(operatorStack) != 0)
                {
                    strcat(operatorStack, " ");
                    strcat(operatorStack, newToken);
                }
                else
                {
                    strcat(operatorStack, newToken);
                }
            }
            else
            {
                if (strlen(operatorStack) != 0)
                {
                    strcat(operatorStack, " ");
                    strcat(operatorStack, "f");
                    strcat(operatorStack, newToken);
                }
                else
                {
                    strcat(operatorStack, "f");
                    strcat(operatorStack, newToken);
                }
            }
        }
        //Reading the next token
        newToken = strtok(NULL, SEPARATORS);
    }

    while (strlen(operatorStack) != 0)
    {
        //While there are tokens in the operatorStack
        //Pop the operator from the operatorStack into the output queue (parsedExpression)
        verificationPointer = strrchr(operatorStack, ' ');

        if (verificationPointer == NULL)
        {
            //If verificationPointer is NULL,
            //there is only one last operator in operatorStack
            verificationPointer = operatorStack;
            
            strcat(parsedExpression, verificationPointer);
            
            //Deleting the operator taken from the operatorStack
            operatorStack[0] = '\0';
        }
        else
        {
            //If the verificationPointer is not NULL,
            //Place it on the next character to read the operator without the space character
            verificationPointer++;

            strcat(parsedExpression, verificationPointer);
            strcat(parsedExpression, " ");
            
            //Deleting the operator taken from the operatorStack
            operatorStack[strlen(operatorStack) - strlen(verificationPointer) - 1] = '\0';
        }
    }

    if (parsedExpression[strlen(parsedExpression) - 1] == ' ')
    {
        parsedExpression[strlen(parsedExpression) - 1] = '\0';
    }
    
    parsedExpression = parsedExpression;
}

void literalExpressionToEvaluationExpression(char *literalExpression, const complex *value, char *evaluationExpression)
{
    //Change the variable to the value

    //Convert the number to text
    char *valueAsText = calloc(NUMBER_AS_TEXT_MAX_CHAR, sizeof(char));
    complexToChar(value, valueAsText);

    //Reading first token
    const char *SEPARATORS = " ";
    char *newToken = strtok(literalExpression, SEPARATORS);

    while (newToken != NULL)
    {
        if (newToken[0] == 'z')
        {
            //If the current token is the variable change it to the value
            strcat(evaluationExpression, valueAsText);
            strcat(evaluationExpression, " ");
        }
        else
        {
            //If the current token is anything else put it into the expression
            strcat(evaluationExpression, newToken);
            strcat(evaluationExpression, " ");
        }
        //Reading next token
        newToken = strtok(NULL, SEPARATORS);
    }
    //Delete the last space character
    evaluationExpression[strlen(evaluationExpression) - 1] = '\0';
}

void evaluateExpressionCalculation(char *evaluationExpression, complex *result)
{
    //Evaluate a parsed expression with variables replace with a value

    //Initialize the supported operator
    OperatorComplex *supportedOperatorList = malloc(sizeof(OperatorComplex) * OPERATOR_COMP_SUPPORTED_COUNT);
    complexOperatorSupportedListGeneration(supportedOperatorList);
    char supportedListCounter = 0;

    //Initialize resultStack and its positionCounter
    complex *resultStack = malloc(sizeof(complex) * INPUT_TEXT_MAX_CHAR_SIZE);
    char positionCounter = 0;
    
    //Initialize the complex for operator evaluation
    complex *operatorResult = malloc(sizeof(complex));
    //Initialze the complex zero for unary function
    complex *complexVoid = calloc(1, sizeof(complex));

    //Initialize control characters for numbers
    const char *CONTROLCHARACTERSnumbers = "1234567890";

    //Read first token
    const char *SEPARATORS = " ";
    char *newToken = strtok(evaluationExpression, SEPARATORS);

    while (newToken != NULL)
    {
        //While there is still token to read
        if (strpbrk(newToken, CONTROLCHARACTERSnumbers) != NULL)
        {
            //If it is a number put it in the resultStack
            readComplexNumber(newToken, resultStack + positionCounter);

            //Place the counter to the next position
            positionCounter++;
        }
        else
        {
            //Identify the operator
            for (supportedListCounter = 0 ; supportedListCounter < OPERATOR_COMP_SUPPORTED_COUNT ; supportedListCounter++)
            {
                if (strcmp(supportedOperatorList[supportedListCounter].operatorText, newToken) == 0)
                {
                    //When the corresponding operator is found jump out of the for loop
                    break;
                }
            }

            if (supportedListCounter >= OPERATOR_COMP_FUNCTIONS_START_RANGE)
            {
                //If the operator is a function
                //Calculate the value to put onto the resultStack
                //with the complex at the top of the resultStack

                //Place the pointer on the previous value, at the top of the resultStack
                positionCounter--;

                supportedOperatorList[supportedListCounter].operationComplexEvaluation(resultStack + positionCounter, complexVoid, operatorResult);

                resultStack[positionCounter] = *operatorResult;
                
                //Place the pointer to the next position
                positionCounter++;
            }
            else
            {
                //Calculate the value to put onto the resultStack
                //With the two complexes at the top of the resultStack

                //Place the pointer on the previous values, second from the top of the resultStack
                positionCounter = positionCounter - 2;

                supportedOperatorList[supportedListCounter].operationComplexEvaluation(resultStack + positionCounter, resultStack + positionCounter + 1, operatorResult);

                resultStack[positionCounter] = *operatorResult;

                //Place the pointer to the next position
                positionCounter++;
            }
        }

        newToken = strtok(NULL, SEPARATORS);
    }

    *result = resultStack[0];
}

void complexPreImageListGeneration(const complex *leftUp, const complex *rightDown, int windowWidth, int windowHeight, complex *preImageList)
{
    //Generate preimage list as the cartesian product of two real numbers lists
    //generated with the real parts and the imaginary parts of the given extremum
    
    double realMin = creal(*leftUp);
    double realMax = creal(*rightDown);
    double imagMin = cimag(*rightDown);
    double imagMax = cimag(*leftUp);

    double realPartStep = ( realMax - realMin ) / windowWidth;
    double imagPartStep = ( imagMax - imagMin ) / windowHeight;
    
    //Initialize loop counter
    unsigned long widthCounter, heightCounter;

    for (heightCounter = 0 ; heightCounter < windowHeight ; heightCounter++)
    {
        for (widthCounter = 0 ; widthCounter < windowWidth ; widthCounter++)
        {
            preImageList[widthCounter + heightCounter * windowWidth] = (realMin + widthCounter * realPartStep) + I * (imagMax - (heightCounter * imagPartStep)); 
        }
    }
}

void complexFunctionCalculation(complex *leftUp, complex *rightDown, int windowWidth, int windowHeight, complex *imageList)
{

    //Generate the preimage list
    complex *preImageList = malloc(sizeof(complex) * (windowWidth) * (windowHeight));
    complexPreImageListGeneration(leftUp, rightDown, windowWidth, windowHeight, preImageList);

    //Memory allocation for the input
    char *literalExpression = malloc(INPUT_TEXT_MAX_CHAR_SIZE * sizeof(char));
    printf("What is the expression to evaluate ? (with 'z' character for the variable)\n");
    readKeyboardInput(literalExpression);

    char *literalExpressionCopy = malloc(INPUT_TEXT_MAX_CHAR_SIZE * sizeof(char));
    literalExpressionCopy[0] = '\0';

    strcpy(literalExpressionCopy, literalExpression);

    //Use the copy and parse the expression
    char *parsedExpression = malloc(INPUT_TEXT_MAX_CHAR_SIZE * sizeof(char));
    parsedExpression[0] = '\0';
    infixToReversePolish(literalExpressionCopy, parsedExpression);
    
    //Initialize the parsedExpression copy
    char *parsedExpressionCopy = malloc(INPUT_TEXT_MAX_CHAR_SIZE * sizeof(char));
    parsedExpressionCopy[0] = '\0';
    strcpy(parsedExpressionCopy, parsedExpression);

    //Initialize evaluation expression
    char *evaluationExpression = malloc(INPUT_TEXT_MAX_CHAR_SIZE * sizeof(char));
    evaluationExpression[0] = '\0';

    //Loop to evaluate the function at each point
    int i;
    for (i = 0 ; i < windowWidth * windowHeight ; i++)
    {
        //Change the variable with a value
        strcpy(parsedExpressionCopy, parsedExpression);
        parsedExpressionCopy[strlen(parsedExpression)] = '\0';
        literalExpressionToEvaluationExpression(parsedExpressionCopy, preImageList + i, evaluationExpression);
        
        //Evaluate the expression
        evaluateExpressionCalculation(evaluationExpression, imageList + i);
        
        //Reinitialize evaluationExpression
        evaluationExpression[0] = '\0';
    }
}

#endif // PARSERTOOL_H
