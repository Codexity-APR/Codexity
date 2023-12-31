#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n,unsigned long int k);

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        unsigned long int n, k;
        scanf("%lu %lu", &n, &k);
        unsigned long int result = returnModPascal(n, k);
        printf("%lu\n", result);
    }
    return 0;
}

unsigned long int returnModPascal(unsigned long int n,unsigned long int k)
{
    unsigned long int MOD = 1000000007;
    unsigned long int result = 1;
    if (k > n-k)
        k = n-k;
    for (unsigned long int i = 0; i < k; i++)
    {
        result = ((result%MOD) * ((n-i)%MOD))%MOD;
        result = ((result%MOD) * (pow(i+1, MOD-2)%MOD))%MOD;
    }
    return result;
}