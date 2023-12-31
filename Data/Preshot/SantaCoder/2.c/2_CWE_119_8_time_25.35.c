#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your marks in Physics, Chemistry and Maths: ");
    scanf("%d %d %d", &p, &c, &m);
    int total_marks = p + c + m;
    float percentage = (total_marks / 3.0);
    printf("\nName: %s\nTotal Marks: %d\nPercentage: %.2f\n", name, total_marks, percentage);
    return 0;
}