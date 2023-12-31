#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i, counter = 0, fCounter = 0, vCounter = 0;
    double* variables = NULL;
    char* function = NULL, input[100], * parsed, Test;

    // allow variable number of inputs
    if ((variables = calloc(100, sizeof(double))) == NULL) // Allocate enough memory for variables
    {
        printf("Memory allocation failed - Variables");
        return (1);
    }

    if ((function = calloc(100, sizeof(char))) == NULL) // Allocate enough memory for the function array
    {
        printf("Memory allocation failed - Functions");
        free(variables);
        return (1);
    }

    // get user input
    printf("Calculator. Please enter the equation.\n");
    fgets(input, sizeof(input), stdin);

    // determine first number, determine function, determine second number
    parsed = input;
    while ((Test = *parsed) != '\n' && Test != EOF && vCounter < 100)
    {
        if (isdigit(*parsed))
        {
            variables[counter] = strtod(parsed, &parsed);
            counter++;
        }
        else if (*parsed == '+' || *parsed == '-' || *parsed == '*' || *parsed == '/')
        {
            function[fCounter] = *parsed;
            fCounter++;
        }
        parsed++;
    }

    // perform the calculation
    double result = variables[0];
    for (i = 0; i < fCounter; i++)
    {
        switch (function[i])
        {
            case '+':
                result += variables[i + 1];
                break;
            case '-':
                result -= variables[i + 1];
                break;
            case '*':
                result *= variables[i + 1];
                break;
            case '/':
                result /= variables[i + 1];
                break;
        }
    }

    // output the result
    printf("Result: %.2f\n", result);

    // free allocated memory
    free(variables);
    free(function);

    return 0;
}