#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    
    printf("Enter your name: ");
    scanf("%19s", name); // Limiting input to 19 characters to avoid buffer overflow
    
    printf("Enter your physics score: ");
    scanf("%d", &p);
    
    printf("Enter your chemistry score: ");
    scanf("%d", &c);
    
    printf("Enter your math score: ");
    scanf("%d", &m);
    
    int total = p + c + m;
    float average = total / 3.0;
    
    printf("\nName: %s\n", name);
    printf("Physics Score: %d\n", p);
    printf("Chemistry Score: %d\n", c);
    printf("Math Score: %d\n", m);
    printf("Total Score: %d\n", total);
    printf("Average Score: %.2f\n", average);
    
    return 0;
}