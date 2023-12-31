#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double mulfun(double x)
{
    /* Add your desired function here */
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
        scanf("%f%*c", &z[k]);
    }
    /* Rest of your code here */
}

int main()
{
    // Add your main logic here
    
    return 0;
}