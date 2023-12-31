#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

int main()
{
    char name[MAX_NAME_LENGTH+1];
    int p, c, m;
    
    printf("Enter your name (up to %d characters):\n", MAX_NAME_LENGTH);
    fgets(name, MAX_NAME_LENGTH+1, stdin);
    name[strcspn(name, "\r\n")] = 0; // remove newline character(s) from input
    
    printf("Enter your password:\n");
    scanf("%d", &p);
    
    printf("Enter your credit card number:\n");
    scanf("%d", &c);
    
    printf("Enter your mobile number:\n");
    scanf("%d", &m);
    
    printf("Hello %s, your password is %d, your credit card number is %d, your mobile number is %d\n", name, p, c, m);
    
    return 0;
}