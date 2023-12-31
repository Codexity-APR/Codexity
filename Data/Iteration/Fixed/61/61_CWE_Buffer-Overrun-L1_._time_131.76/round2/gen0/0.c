#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i, counter = 0, fCounter = 0, vCounter = 0;
    double* variables = NULL;
    char* function = NULL, input[100], * parsed, Test;

    // Allow variable number of inputs
    if ((variables = calloc(1, sizeof(double))) == NULL)
    {
        printf("Memory allocation failed - Variables");
        return (1);
    }

    // Allocate memory for function array
    if ((function = calloc(100, sizeof(char))) == NULL)
    {
        printf("Memory allocation failed - Functions");
        free(variables);
        return (1);
    }

    // Get user input
    printf("Calculator. Please enter the equation.\n");
    fgets(input, sizeof(input), stdin);

    // Determine first number, determine function, determine second number
    parsed = input;
    while ((Test = *parsed) != '\n' && Test != EOF && vCounter < 100)
    {
        if (isdigit(*parsed))
        {
            variables[counter] = strtod(parsed, &parsed);
            counter++;

            // Reallocate memory for variables array
            double* temp = realloc(variables, (counter + 1) * sizeof(double));
            if (temp == NULL)
            {
                printf("Memory allocation failed - Variables");
                free(variables);
                free(function);
                return (1);
            }
            variables = temp;
        }
        else if (*parsed == '+' || *parsed == '-' || *parsed == '*' || *parsed == '/')
        {
            function[fCounter] = *parsed;
            fCounter++;
        }
        parsed++;
    }

    // Perform calculation based on the function
    double result = variables[0];
    for (i = 0; i < fCounter; i++)
    {
        if (i + 1 < counter)
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
    }

    printf("Result: %.2f\n", result);

    free(variables);
    free(function);

    return 0;
}