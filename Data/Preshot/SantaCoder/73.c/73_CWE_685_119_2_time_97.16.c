#include <stdio.h>
#include <string.h>

int main()
{
    int number1, number2;
    char expression[2];

    printf("This is a program to execute arithmetic in binary.\n");
    printf("The program will ask you for input in the form of two binary numbers separated by an arithmetic expression (+ - / * %).\n");
    printf("The binary numbers must be only 1's and 0's and a maximum of seven digits each.\n");
    printf("You may exit the program by typing 'exit'.\n");

    while (1)
    {
        printf("\nEnter first binary number: ");
        scanf("%d", &number1);
        printf("Enter second binary number: ");
        scanf("%d", &number2);
        printf("Which expression would you like (+ - / * %): ");
        scanf("%s", expression);

        if (strcmp(expression, "+") == 0)
        {
            printf("Result: %d\n", number1 + number2);
        }
        else if (strcmp(expression, "-") == 0)
        {
            printf("Result: %d\n", number1 - number2);
        }
        else if (strcmp(expression, "*") == 0)
        {
            printf("Result: %d\n", number1 * number2);
        }
        else if (strcmp(expression, "/") == 0)
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
        else if (strcmp(expression, "%") == 0)
        {
            printf("Result: %d\n", number1 % number2);
        }
        else if (strcmp(expression, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("Error: Invalid expression\n");
        }
    }

    return 0;
}