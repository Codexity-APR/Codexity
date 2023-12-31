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
    scanf("%d", &u);
    u = u + 1;
    float z[u];
    int k;
    for (k = u - 1; k >= 0; k--)
    {
        printf("\nInsert coefficient of x^%d\t", k);
        scanf("%f%*c", &z[k]);
    }
    
    double result = 0;
    for (int i = u - 1; i >= 0; i--)
    {
        result += z[i] * pow(x, i);
    }
    
    return result;
}

int main()
{
    double x;
    printf("Enter a value for x:\t");
    scanf("%lf", &x);
    
    double result1 = mulfun(x);
    printf("Result of mulfun(x):\t%.2lf\n", result1);
    
    double result2 = polynomial(x);
    printf("Result of polynomial(x):\t%.2lf\n", result2);
    
    return 0;
}