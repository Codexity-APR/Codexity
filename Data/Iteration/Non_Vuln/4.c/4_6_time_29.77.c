#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n, unsigned long int k);

int main()
{
    int t;

    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    while (t > 0)
    {
        unsigned long int n, k;
        printf("Enter the values of n and k: ");
        scanf("%lu %lu", &n, &k);

        unsigned long int result = returnModPascal(n, k);
        printf("The modulo value of %luC%lu is %lu\n", n, k, result);

        t--;
    }

    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    unsigned long int numerator = 1;
    unsigned long int denominator = 1;

    for (unsigned long int i = 0; i < k; i++)
    {
        numerator *= (n - i);
        denominator *= (i + 1);
    }

    unsigned long int result = numerator / denominator;
    return result;
}