#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p,c,m;
    printf("Enter your name: ");
    fgets(name,sizeof(name),stdin);
    printf("Enter your password: ");
    scanf("%d",&p);
    printf("Enter your credit card number: ");
    scanf("%d",&c);
    printf("Enter your mobile number: ");
    scanf("%d",&m);
    printf("Hello %s, your password is %d, your credit card number is %d, and your mobile number is %d.\n",name,p,c,m);
    return 0;
}