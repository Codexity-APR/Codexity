#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double mulfun(double x)
{
    double q = (x * x + 5 * x + 1);
    double s = exp(x) * q;
    return s;
}

double polynomial(double x)
{
    int u;
    printf("Insert degree of this polynomial?\t");
    scanf("%d", &u);
    u = u + 1;
    float z[u];
    memset(z, 0, sizeof(z)); // Initialize the array with zeros
    int k;
    for (k = u - 1; k >= 0; k--)
    {
        printf("\nInsert coefficient of x^%d\t", k);
        scanf("%f%*c", &z[k]);
    }
    double result = 0.0;
    for (k = u - 1; k >= 0; k--)
    {
        result += z[k] * pow(x, k);
    }
    return result;
}

int main()
{
    double x;
    printf("Enter a value for x:\t");
    scanf("%lf", &x);
    double result1 = mulfun(x);
    printf("Result of mulfun: %.3lf\n", result1);
    double result2 = polynomial(x);
    printf("Result of polynomial: %.3lf\n", result2);
    return 0;
}