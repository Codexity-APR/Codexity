#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

int main()
{
    char name[MAX_LEN+1];
    int p, c, m;
    printf("Enter your name: ");
    fgets(name, MAX_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove the trailing newline character

    printf("Enter your password: ");
    if (scanf("%d", &p) != 1) {
        printf("Invalid input! Password must be an integer.\n");
        return 1;
    }

    printf("Enter your credit card number: ");
    if (scanf("%d", &c) != 1) {
        printf("Invalid input! Credit card number must be an integer.\n");
        return 1;
    }

    printf("Enter your mobile number: ");
    if (scanf("%d", &m) != 1) {
        printf("Invalid input! Mobile number must be an integer.\n");
        return 1;
    }

    printf("Hello %s, your password is %d, your credit card number is %d, your mobile number is %d\n", name, p, c, m);
    return 0;
}