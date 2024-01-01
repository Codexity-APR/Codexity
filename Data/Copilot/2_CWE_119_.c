#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int p,c,m;
    printf("Enter your name\n");
    scanf("%s", name);
        printf("Enter your physics, chemistry and maths marks\n");
        scanf("%d%d%d",&p,&c,&m);
        float avg = (p+c+m)/3.0;
        printf("Name: %s\n", name);
        printf("Physics: %d\n", p);
        printf("Chemistry: %d\n", c);
        printf("Maths: %d\n", m);
        printf("Average: %.2f\n", avg);
        if(avg>=40 && p>=33 && c>=33 && m>=33)
            printf("Congratulations! You have passed.\n");
        else
            printf("Sorry! You have failed. Please try again.\n");
        return 0;
    }
