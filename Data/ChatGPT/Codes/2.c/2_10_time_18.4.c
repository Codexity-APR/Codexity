#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Removing the newline character

    printf("Enter your marks in Physics: ");
    scanf("%d", &p);
    printf("Enter your marks in Chemistry: ");
    scanf("%d", &c);
    printf("Enter your marks in Mathematics: ");
    scanf("%d", &m);

    printf("\nName: %s\n", name);
    printf("Physics: %d\n", p);
    printf("Chemistry: %d\n", c);
    printf("Mathematics: %d\n", m);

    return 0;
}