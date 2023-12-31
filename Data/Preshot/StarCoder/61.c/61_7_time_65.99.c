#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i, counter = 0, fCounter = 0, vCounter = 0;
    double* variables = NULL;
    char* function = NULL, input[100], * parsed, Test;
    
    //allow variable number of inputs
    variables = calloc(2, sizeof(double));
    if (variables == NULL)
    {
        printf("Memory allocation failed - Variables");
        return (1);
    }
    
    function = calloc(1, sizeof(char));
    if (function == NULL)
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

    //calculate the result
    if (fCounter > 0)
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
                printf("%lf\n", variables[0] / variables[1]);
                break;
            default:
                printf("Invalid function\n");
                break;
        }
    }
    else
    {
        printf("No function provided\n");
    }

    //free memory
    free(variables);
    free(function);
    return (0);
}