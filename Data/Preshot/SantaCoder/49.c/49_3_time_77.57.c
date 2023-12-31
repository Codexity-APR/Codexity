#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double mulfun(double x)
{
    /*I want to add function from the black screen here*/
    double q = (x * x + 5 * x + 1); //but you can change q to any functions you want
    double s = exp(x) * q;          //this is basically homework :)
    return s;
}

double polynomial(double x)
{
    int u;
    printf("Insert degree of this polynomial?\t");
    if (scanf("%d", &u) != 1) {
        printf("Error: Invalid input for degree of polynomial.\n");
        exit(1);
    }
    u = u + 1;
    float z[u];
    int k;
    for (k = u - 1; k >= 0; k--)
    {
        printf("\nInsert coefficient of x^%d\t", k);
        if (scanf("%f", &z[k]) != 1) {
            printf("Error: Invalid input for coefficient of x^%d.\n", k);
            exit(1);
        }
    }
    return 0;
}

int main()
{
    double x;
    printf("Insert x value\t");
    if (scanf("%lf", &x) != 1) {
        printf("Error: Invalid input for x value.\n");
        exit(1);
    }
    mulfun(x);
    printf("The result is %lf\n", mulfun(x));
    polynomial(x);
    printf("The result is %lf\n", polynomial(x));
    return 0;
}