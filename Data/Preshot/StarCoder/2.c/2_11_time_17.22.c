#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 19 // Maximum length of input string

int main()
{
    char name[MAX_INPUT_LENGTH+1]; // +1 for null termination
    int p,c,m;
    printf("Enter your name (max %d characters): ", MAX_INPUT_LENGTH);
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline character
    printf("Enter your password: ");
    scanf("%d",&p);
    printf("Enter your credit card number: ");
    scanf("%d",&c);
    printf("Enter your mobile number: ");
    scanf("%d",&m);
    printf("Hello %s, your password is %d, your credit card number is %d, your mobile number is %d\n",name,p,c,m);
    return 0;
}