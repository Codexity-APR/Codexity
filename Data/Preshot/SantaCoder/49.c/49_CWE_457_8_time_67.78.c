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
    printf("Insert x value: ");
    scanf("%lf", &x);

    printf("Insert degree of the polynomial: ");
    int u;
    scanf("%d", &u);
    u = u + 1;
    float z[u];
    int k;
    for (k = u - 1; k >= 0; k--)
    {
        printf("\nInsert coefficient of x^%d: ", k);
        scanf("%f", &z[k]);
    }

    double result1 = mulfun(x);
    printf("\nThe result of the function mulfun is: %lf\n", result1);
    
    double result2 = 0;
    for (k = u - 1; k >= 0; k--)
    {
        result2 += z[k] * pow(x, k);
    }
    printf("\nThe result of the polynomial is: %lf\n", result2);
    
    return 0;
}