#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

int main()
{
    int i, counter = 0, fCounter = 0, vCounter = 0;
    double* variables = NULL;
    char* function = NULL, input[MAX_INPUT_SIZE], * parsed, Test;
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
    while ((*parsed) != '\n' && (*parsed) != EOF && vCounter < MAX_INPUT_SIZE)
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

    if (counter < 2)
    {
        printf("Invalid input: Missing operand(s)\n");
        return 1;
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
        if (variables[1] == 0)
        {
            printf("Invalid input: Division by zero\n");
            return 1;
        }
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