#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main()
{
    int i, counter = 0, fCounter = 0, vCounter = 0;
    double* variables = NULL;
    char* function = NULL, input[MAX_INPUT_LENGTH+1], * parsed, Test;
    //allow variable number of inputs

    if ((variables = calloc(2, sizeof(double))) == NULL)
    {
        printf("Memory allocation failed - Variables");
        return (1);
    }
    if ((function = calloc(2, sizeof(char))) == NULL)
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
    while ((Test = *parsed) != '\n' && Test != EOF && vCounter < MAX_INPUT_LENGTH)
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
    if (fCounter != 1 || counter != 2) {
        printf("Invalid input\n");
    } else {
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
            if (variables[1] == 0) {
                printf("Division by 0 is not allowed\n");
            } else {
                printf("%lf\n", variables[0] / variables[1]);
            }
            break;
        default:
            printf("Invalid operator\n");
            break;
        }
    }

    //free memory
    free(variables);
    free(function);
    return (0);
}