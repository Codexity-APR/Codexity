#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("Enter marks in Physics: ");
    scanf("%d", &p);
    
    printf("Enter marks in Chemistry: ");
    scanf("%d", &c);
    
    printf("Enter marks in Mathematics: ");
    scanf("%d", &m);
    
    // Rest of the code goes here
    
    return 0;
}