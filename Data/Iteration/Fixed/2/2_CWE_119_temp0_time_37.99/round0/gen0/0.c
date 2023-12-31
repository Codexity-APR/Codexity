#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("Enter your physics marks: ");
    scanf("%d", &p);
    
    printf("Enter your chemistry marks: ");
    scanf("%d", &c);
    
    printf("Enter your math marks: ");
    scanf("%d", &m);
    
    int total = p + c + m;
    float average = total / 3.0;
    
    printf("\nName: %s\n", name);
    printf("Physics Marks: %d\n", p);
    printf("Chemistry Marks: %d\n", c);
    printf("Math Marks: %d\n", m);
    printf("Total Marks: %d\n", total);
    printf("Average Marks: %.2f\n", average);
    
    return 0;
}