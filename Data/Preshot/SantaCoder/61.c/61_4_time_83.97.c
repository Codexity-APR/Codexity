#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int i, counter = 0, fCounter = 0, vCounter = 0;
    double* variables = NULL;
    char* function = NULL, input[100], * parsed;
    char Test;
    
    //allow variable number of inputs
    variables = (double*)calloc(1, sizeof(double));
    if (variables == NULL)
    {
        printf("Memory allocation failed - Variables");
        return (1);
    }
    
    function = (char*)calloc(1, sizeof(char));
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
#ifdef __cplusplus
            fCounter++;
#endif
            vCounter++;
        }
        parsed++;
    }
    
    free(variables);
    free(function);

    return 0;
}