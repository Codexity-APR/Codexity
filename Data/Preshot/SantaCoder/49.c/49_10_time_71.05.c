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
    int k;
    for (k = u - 1; k >= 0; k--)
    {
        printf("\nInsert coefficient of x^%d\t", k);
        scanf("%f", &z[k]);
    }
}

int main()
{
    double x;
    printf("Insert x value: ");
    scanf("%lf", &x);
    
    polynomial(x);
    printf("\n\n");

    double res1 = mulfun(x);
    printf("The result of mulfun is: %lf\n", res1);
    
    double res2 = polynomial(x);
    printf("The result of polynomial is: %lf\n", res2);

    return 0;
}