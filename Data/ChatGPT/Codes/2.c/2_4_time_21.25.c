#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove the newline character
    
    printf("Enter your physics marks: ");
    scanf("%d", &p);
    
    printf("Enter your chemistry marks: ");
    scanf("%d", &c);
    
    printf("Enter your math marks: ");
    scanf("%d", &m);
    
    printf("\n");
    printf("Name: %s\n", name);
    printf("Physics Marks: %d\n", p);
    printf("Chemistry Marks: %d\n", c);
    printf("Math Marks: %d\n", m);
    
    return 0;
}