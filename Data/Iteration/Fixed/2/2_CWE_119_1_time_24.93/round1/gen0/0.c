#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    
    printf("Enter your name: ");
    scanf("%19s", name); // Limiting the input to 19 characters
    
    printf("Enter your physics score: ");
    scanf("%d", &p);
    
    printf("Enter your chemistry score: ");
    scanf("%d", &c);
    
    printf("Enter your math score: ");
    scanf("%d", &m);
    
    // Rest of the code goes here
    
    return 0;
}