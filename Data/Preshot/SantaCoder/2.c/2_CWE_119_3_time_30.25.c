#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p,c,m;
    printf("Enter your name\n");
    scanf("%s", name);
    printf("Enter your marks in Physics, Chemistry and Mathematics: ");
    scanf("%d %d %d", &p, &c, &m);
    float average = (p + c + m) / 3.0;
    printf("Name: %s\n", name);
    printf("Physics: %d\n", p);
    printf("Chemistry: %d\n", c);
    printf("Mathematics: %d\n", m);
    printf("Average marks: %.2f\n", average);
    return 0;
}