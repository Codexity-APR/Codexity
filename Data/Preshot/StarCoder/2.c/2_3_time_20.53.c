#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

int main()
{
    char name[MAX_LENGTH+1]; // 1 extra space for the null character
    int p, c, m;
    printf("Enter your name (max length %d): ", MAX_LENGTH);
    fgets(name, MAX_LENGTH+1, stdin); // reading input using fgets()
    name[strcspn(name, "\n")] = '\0'; // removing the newline character

    printf("Enter your password: ");
    scanf("%d", &p);

    printf("Enter your credit card number: ");
    scanf("%d", &c);

    printf("Enter your mobile number: ");
    scanf("%d", &m);

    printf("Hello %s, your password is %d, your credit card number is %d, your mobile number is %d\n", name, p, c, m);
    return 0;
}