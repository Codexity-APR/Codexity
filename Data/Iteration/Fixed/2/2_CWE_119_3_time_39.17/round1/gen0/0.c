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
    
    printf("\n---- Student Details ----\n");
    printf("Name: %s\n", name);
    printf("Physics score: %d\n", p);
    printf("Chemistry score: %d\n", c);
    printf("Math score: %d\n", m);
    printf("Total score: %d\n", total);
    printf("Average score: %.2f\n", average);
    
    return 0;
}