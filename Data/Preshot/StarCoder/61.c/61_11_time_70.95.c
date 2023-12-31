#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_VARIABLES 100

int main()
{
    int i, counter = 0, fCounter = 0, vCounter = 0;
    double* variables = NULL;
    char* function = NULL, input[MAX_INPUT_LENGTH], * parsed;
    char operator = 0;

    //allow variable number of inputs
    variables = calloc(MAX_VARIABLES, sizeof(double));
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
    fgets(input, MAX_INPUT_LENGTH, stdin);

    //determine first number, determine function, determine second number
    parsed = input;
    while (*parsed != '\n' && *parsed != EOF && vCounter < MAX_VARIABLES)
    {
        if (isdigit(*parsed))
        {
            variables[counter++] = strtod(parsed, &parsed);
            vCounter++;
        }
        else if (operator == 0 && (*parsed == '+' || *parsed == '-' || *parsed == '*' || *parsed == '/'))
        {
            operator = *parsed;
            parsed++;
        }
        else if (isspace(*parsed))
        {
            parsed++;
        }
        else
        {
            printf("Invalid input\n");
            free(variables);
            free(function);
            return (1);
        }
    }

    //calculate the result
    switch (operator)
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
        printf("Invalid operator\n");
        free(variables);
        free(function);
        return (1);
    }

    //free memory
    free(variables);
    free(function);
    return (0);
}