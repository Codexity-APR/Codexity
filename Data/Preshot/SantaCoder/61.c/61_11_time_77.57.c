#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

int main()
{
    int i, counter = 0, vCounter = 0;
    double* variables = NULL;
    char* function = NULL, input[MAX_INPUT_SIZE], * parsed;
    char test;

    //allow variable number of inputs
    if ((variables = calloc(1, sizeof(double))) == NULL)
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
    fgets(input, MAX_INPUT_SIZE, stdin);

    //determine first number, determine function, determine second number
    parsed = input;
    while ((test = *parsed) != '\n' && test != EOF && vCounter < MAX_INPUT_SIZE)
    {
        if (isdigit(*parsed))
        {
            variables[counter] = strtod(parsed, &parsed);
            counter++;
            vCounter++;
        }
        parsed++;
    }
    
    free(variables);
    free(function);

    return 0;
}