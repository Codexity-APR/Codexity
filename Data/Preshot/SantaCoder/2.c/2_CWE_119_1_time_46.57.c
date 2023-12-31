#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your physics, chemistry and maths marks: ");
    scanf("%d %d %d", &p, &c, &m);

    float avg = (p + c + m) / 3.0;
    printf("%s, your average marks are %.2f\n", name, avg);

    if (avg >= 60) {
        printf("Congratulations %s! You have passed with First Division\n", name);
    } else if (avg >= 50) {
        printf("Congratulations %s! You have passed with Second Division\n", name);
    } else if (avg >= 40) {
        printf("Congratulations %s! You have passed with Third Division\n", name);
    } else {
        printf("Sorry %s, you have failed. Better luck next time!\n", name);
    }

    return 0;
}