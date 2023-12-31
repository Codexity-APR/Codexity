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
        printf("The value of C(%lu, %lu) modulo 1000000007 is %lu\n", n, k, result);

        t--;
    }

    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    unsigned long int pascal[n + 1][k + 1];

    for (unsigned long int i = 0; i <= n; i++)
    {
        for (unsigned long int j = 0; j <= k && j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                pascal[i][j] = 1;
            }
            else
            {
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % 1000000007;
            }
        }
    }

    return pascal[n][k];
}