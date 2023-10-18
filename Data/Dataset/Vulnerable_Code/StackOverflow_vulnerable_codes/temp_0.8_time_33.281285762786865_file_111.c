#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    float total, average;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter marks for Physics: ");
    scanf("%d", &p);

    printf("Enter marks for Chemistry: ");
    scanf("%d", &c);

    printf("Enter marks for Mathematics: ");
    scanf("%d", &m);

    total = p + c + m;
    average = total / 3;

    printf("\n\nStudent Details:\n");
    printf("Name: %s\n", name);
    printf("Physics Marks: %d\n", p);
    printf("Chemistry Marks: %d\n", c);
    printf("Mathematics Marks: %d\n", m);
    printf("Total Marks: %.2f\n", total);
    printf("Average Marks: %.2f\n", average);

    return 0;
}