#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

int main()
{
    char name[MAX_LEN + 1]; // Add 1 for null terminator
    int p, c, m;
    printf("Enter your name (up to %d characters):\n", MAX_LEN);
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline
    printf("Enter your password:\n");
    scanf("%d", &p);
    printf("Enter your credit card number:\n");
    scanf("%d", &c);
    printf("Enter your mobile number:\n");
    scanf("%d", &m);
    printf("Hello %s, your password is %d, your credit card number is %d, your mobile number is %d\n", name, p, c, m);
    return 0;
}