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
        unsigned long int n,k;
        scanf("%lu %lu", &n, &k);
        printf("%lu\n", returnModPascal(n,k));
    }
    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    if (k > n - k) 
        k = n - k; 
    unsigned long int res = 1; 
    for (unsigned long int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res % 1000000007; 
}