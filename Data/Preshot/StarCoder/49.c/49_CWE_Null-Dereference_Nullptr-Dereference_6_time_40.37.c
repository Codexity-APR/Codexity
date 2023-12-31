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

    // Dynamically allocate memory for storing the coefficients of the polynomial
    double *coefficients = (double *)malloc((u + 1) * sizeof(double));

    //Take input for each coefficient
    for (int i = 0; i <= u; i++)
    {
        printf("Insert coefficient of x^%d:\t", i);
        scanf("%lf", &coefficients[i]);
    }

    double result = 0;
    for (int i = 0; i <= u; i++)
    {
        result += coefficients[i] * pow(x, i);
    }

    // Free the dynamically allocated memory
    free(coefficients);
    
    return result;
}

int main()
{
    double x;
    printf("Insert x:\t");
    scanf("%lf", &x);
    printf("Result is %lf\n", mulfun(x));
    printf("Result of polynomial is %lf\n", polynomial(x));
    return 0;
}