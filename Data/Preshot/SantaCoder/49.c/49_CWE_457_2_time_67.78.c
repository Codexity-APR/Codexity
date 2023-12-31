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

int main()
{
    double x;
    printf("Insert x value:\t");
    scanf("%lf", &x);
    printf("The result is:\t%lf\n", mulfun(x));

    int u;
    printf("Insert degree of this polynomial?:\t");
    scanf("%d", &u);
    u = u + 1;
    float z[u];
    int k;
    for (k = u - 1; k >= 0; k--)
    {
        printf("\nInsert coefficient of x^%d:\t", k);
        scanf("%f", &z[k]);
    }
    printf("\n\n");

    double result = 0;
    for (k = u - 1; k >= 0; k--)
    {
        result += z[k] * pow(x, k);
    }

    printf("The result is:\t%lf\n", result);

    return 0;
}