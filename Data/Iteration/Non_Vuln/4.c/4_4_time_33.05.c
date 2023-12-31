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
        printf("Enter the value of n: ");
        scanf("%lu", &n);
        printf("Enter the value of k: ");
        scanf("%lu", &k);

        unsigned long int result = returnModPascal(n, k);
        printf("The result is: %lu\n", result);

        t--;
    }

    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    if (k > n - k)
    {
        k = n - k;
    }

    unsigned long int result = 1;

    for (unsigned long int i = 0; i < k; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}