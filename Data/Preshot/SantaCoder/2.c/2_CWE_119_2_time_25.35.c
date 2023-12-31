#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p,c,m;
    printf("Enter your name\n");
    scanf("%s", name);
    printf("Enter your marks in Physics, Chemistry and Mathematics:\n");
    scanf("%d %d %d", &p, &c, &m);
    float total = p + c + m;
    float average = total / 3;
    printf("Name: %s\nTotal marks: %.2f\nAverage marks: %.2f\n", name, total, average);
    return 0;
}