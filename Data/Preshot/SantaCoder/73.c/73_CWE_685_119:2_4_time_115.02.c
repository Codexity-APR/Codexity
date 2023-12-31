#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int number1, number2;
    char expression;
    char input[10];

    printf("This is a program to execute arithmetic in binary.\n");
    printf("The program will ask you for input in the form of two binary numbers separated by an arithmetic expression (+ - / * %).\n");
    printf("The binary numbers must be only 1's and 0's and a maximum of seven digits each.\n");
    printf("You may exit the program by typing 'exit'.\n");

    while (1)
    {
        printf("\nEnter first binary number: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0)
        {
            exit(0);
        }
        number1 = strtol(input, NULL, 2);

        printf("Enter second binary number: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0)
        {
            exit(0);
        }
        number2 = strtol(input, NULL, 2);

        printf("Which expression would you like (+ - / * %): ");
        scanf(" %c", &expression);
        expression = toupper(expression);

        if (expression == '+')
        {
            printf("Result: %d\n", number1 + number2);
        }
        else if (expression == '-')
        {
            printf("Result: %d\n", number1 - number2);
        }
        else if (expression == '*')
        {
            printf("Result: %d\n", number1 * number2);
        }
        else if (expression == '/')
        {
            if (number2 == 0)
            {
                printf("Error: Division by zero\n");
            }
            else
            {
                printf("Result: %d\n", number1 / number2);
            }
        }
        else if (expression == '%')
        {
            printf("Result: %d\n", number1 % number2);
        }
        else
        {
            printf("Invalid expression. Please try again.\n");
        }
    }

    return 0;
}