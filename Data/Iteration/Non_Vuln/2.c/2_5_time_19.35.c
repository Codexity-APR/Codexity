#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    
    printf("Enter your physics score: ");
    scanf("%d", &p);
    
    printf("Enter your chemistry score: ");
    scanf("%d", &c);
    
    printf("Enter your math score: ");
    scanf("%d", &m);
    
    printf("Name: %s\n", name);
    printf("Physics score: %d\n", p);
    printf("Chemistry score: %d\n", c);
    printf("Math score: %d\n", m);
    
    return 0;
}