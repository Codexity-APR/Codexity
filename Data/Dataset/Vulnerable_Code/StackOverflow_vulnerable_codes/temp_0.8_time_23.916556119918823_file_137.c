#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p,c,m;
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your physics score: ");
    scanf("%d", &p);

    printf("Enter your chemistry score: ");
    scanf("%d", &c);

    printf("Enter your math score: ");
    scanf("%d", &m);

    int total = p + c + m;
    float average = total / 3.0;

    printf("\nName: %s\n", name);
    printf("Physics: %d\n", p);
    printf("Chemistry: %d\n", c);
    printf("Math: %d\n", m);
    printf("Total: %d\n", total);
    printf("Average: %.2f\n", average);

    return 0;
}