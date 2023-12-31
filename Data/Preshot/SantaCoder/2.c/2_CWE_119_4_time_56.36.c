#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p, c, m;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nEnter your marks in Physics, Chemistry and Maths respectively: ");
    scanf("%d%d%d", &p, &c, &m);
    
    float avg = (p + c + m) / 3.0;
    printf("\nName: %s\nPhysics: %d\nChemistry: %d\nMaths: %d\n", name, p, c, m);
    printf("Average marks: %.2f\n", avg);
    
    if (avg >= 60.0)
    {
        printf("Congratulations! You have passed with First Division.\n");
    }
    else if (avg >= 50.0)
    {
        printf("Congratulations! You have passed with Second Division.\n");
    }
    else if (avg >= 40.0)
    {
        printf("Congratulations! You have passed with Third Division.\n");
    }
    else
    {
        printf("Sorry, you have failed.\n");
    }
    
    return 0;
}