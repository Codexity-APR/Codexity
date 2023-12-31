#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i, counter = 0, fCounter = 0, vCounter = 0;
    double* variables = NULL;
    char* function = NULL, input[100], * parsed, Test;
    //allow variable number of inputs

    if ((variables = calloc(2, sizeof(double))) == NULL)
    {
        printf("Memory allocation failed - Variables");
        return (1);
    }
    if ((function = calloc(1, sizeof(char))) == NULL)
    {
        printf("Memory allocation failed - Functions");
        free(variables);
        return (1);
    }


    //get user input
    printf("Calculator. Please enter the equation.\n");
    fgets(input, sizeof(input), stdin);

    //determine first number, determine function, determine second number
    parsed = input;
    while ((Test = *parsed) != '\n' && Test != EOF && vCounter < 100)
    {
        if (isdigit(*parsed))
        {
            variables[counter] = strtod(parsed, &parsed);
            counter++;
            vCounter++;
        }
        else if (isalpha(*parsed))
        {
            function[fCounter] = *parsed;
            fCounter++;
            parsed++;
        }
        parsed++;
    }

    if (counter != 2) 
    {
        printf("Invalid number of operands!\n");
        free(variables);
        free(function);
        return (1);
    }

    //calculate the result
    switch (function[0])
    {
    case '+':
        printf("%lf\n", variables[0] + variables[1]);
        break;
    case '-':
        printf("%lf\n", variables[0] - variables[1]);
        break;
    case '*':
        printf("%lf\n", variables[0] * variables[1]);
        break;
    case '/':
        printf("%lf\n", variables[0] / variables[1]);
        break;
    default:
        printf("Invalid function\n");
        break;
    }

    //free memory
    free(variables);
    free(function);
    return (0);
}