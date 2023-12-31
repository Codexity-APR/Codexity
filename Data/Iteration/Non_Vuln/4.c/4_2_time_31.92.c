#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n, unsigned long int k);

int main()
{
    int t;
    unsigned long int n, k;

    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        printf("\nTest case %d:\n", i + 1);
        printf("Enter the value of n: ");
        scanf("%lu", &n);
        printf("Enter the value of k: ");
        scanf("%lu", &k);

        unsigned long int result = returnModPascal(n, k);
        printf("Result: %lu\n", result);
    }

    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    if (k == 0 || k == n)
        return 1;

    unsigned long int numerator = 1;
    unsigned long int denominator = 1;

    for (unsigned long int i = 1; i <= k; i++)
    {
        numerator *= (n - i + 1);
        denominator *= i;
    }

    return numerator / denominator;
}