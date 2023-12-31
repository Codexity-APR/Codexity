#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    int totalMarks;
    float averageMarks;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    printf("Enter your marks in Physics: ");
    scanf("%d", &p);

    printf("Enter your marks in Chemistry: ");
    scanf("%d", &c);

    printf("Enter your marks in Mathematics: ");
    scanf("%d", &m);

    totalMarks = p + c + m;
    averageMarks = (float)totalMarks / 3;

    printf("Name: %s\n", name);
    printf("Physics: %d\n", p);
    printf("Chemistry: %d\n", c);
    printf("Mathematics: %d\n", m);
    printf("Total Marks: %d\n", totalMarks);
    printf("Average Marks: %.2f\n", averageMarks);

    return 0;
}