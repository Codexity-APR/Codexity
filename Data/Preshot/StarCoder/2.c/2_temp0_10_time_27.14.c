#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

int main()
{
    char name[MAX_NAME_LENGTH+1]; // +1 for null terminator
    int p, c, m;
    printf("Enter your name (up to %d characters)\n", MAX_NAME_LENGTH);
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline
    printf("Enter your password\n");
    if (scanf("%d", &p) != 1) {
        printf("Error reading input\n");
        return 1;
    }
    printf("Enter your credit card number\n");
    if (scanf("%d", &c) != 1) {
        printf("Error reading input\n");
        return 1;
    }
    printf("Enter your mobile number\n");
    if (scanf("%d", &m) != 1) {
        printf("Error reading input\n");
        return 1;
    }
    printf("Hello %s, your password is %d, your credit card number is %d, your mobile number is %d\n", name, p, c, m);
    return 0;
}