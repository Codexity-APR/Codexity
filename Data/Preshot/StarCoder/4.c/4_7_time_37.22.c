#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n,unsigned long int k);

int main()
{
    int t;
    scanf("%d", &t);

    // iterate over test cases
    while(t--)
    {
        unsigned long int n, k;
        scanf("%lu %lu", &n, &k);
        printf("%lu\n", returnModPascal(n, k));
    }

    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    unsigned long int i, j, sum = 0;
    
    // iterate over pascal's triangle
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            // compute i raised to the power of j
            unsigned long int term = 1;
            for(int t = 1; t <= j; t++)
            {
                term = term * i;
            }
            
            // add the term to the sum
            sum += term;
        }
    }
    
    // return the sum mod k
    return sum % k;
}