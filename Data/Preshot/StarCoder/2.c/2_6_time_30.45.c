#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 20

int main()
{
    char name[MAX_INPUT_LENGTH + 1];
    int p, c, m;
    printf("Enter your name (max %d characters): ", MAX_INPUT_LENGTH);
    if (fgets(name, MAX_INPUT_LENGTH + 1, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline character

    printf("Enter your password: ");
    if (scanf("%d", &p) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    printf("Enter your credit card number: ");
    if (scanf("%d", &c) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    printf("Enter your mobile number: ");
    if (scanf("%d", &m) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    printf("Hello %s, your password is %d, your credit card number is %d, your mobile number is %d\n", name, p, c, m);
    return 0;
}