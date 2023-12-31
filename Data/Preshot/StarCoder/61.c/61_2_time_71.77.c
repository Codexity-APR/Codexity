#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_VARIABLES 100

int main()
{
    int i, counter = 0, fCounter = 0, vCounter = 0;
    double* variables = NULL;
    char* function = NULL, input[100], * parsed;
    //allow variable number of inputs

    if ((variables = calloc(MAX_VARIABLES, sizeof(double))) == NULL)
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
    while (*parsed != '\n' && *parsed != EOF && vCounter < MAX_VARIABLES)
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

    //calculate the result
    if (fCounter != 1 || vCounter != 2)
    {
        printf("Invalid equation. Please enter an equation in the form: <number> <function> <number>\n");
    }
    else
    {
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
            if (variables[1] == 0)
            {
                printf("Division by zero error!\n");
            }
            else
            {
                printf("%lf\n", variables[0] / variables[1]);
            }
            break;
        default:
            printf("Invalid function\n");
            break;
        }
    }

    //free memory
    free(variables);
    free(function);
    return (0);
}