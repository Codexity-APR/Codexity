List of vulnerabilities detected: 
 Error type: CWE-457 at line: 31. Error message: Uninitialized variable: z


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
double mulfun(double x)
{
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
    double p = 0;
    for (k = u - 1; k >= 0; k--)
    {
        p += z[k] * pow(x, k);
    }
    return p;
}
int main()
{
    double x = 2.5;
    double result = mulfun(x);
    printf("mulfun(%f) = %f\n", x, result);
    x = 3.0;
    result = polynomial(x);
    printf("polynomial(%f) = %f\n", x, result);
    return 0;
}