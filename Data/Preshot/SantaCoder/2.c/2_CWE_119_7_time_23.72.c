#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p,c,m;
    printf("Enter your name\n");
    scanf("%s", name);
    printf("Enter your marks in physics, chemistry and maths\n");
    scanf("%d%d%d", &p, &c, &m);
    float average = (p + c + m) / 3.0;
    printf("Name: %s\nPhysics: %d\nChemistry: %d\nMaths: %d\nAverage: %f\n", name, p, c, m, average);
    return 0;
}