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
        printf("%lu\n", returnModPascal(n, k));
    }
    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    if (k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    unsigned long int res = 1;
    for (unsigned long int i = 1; i <= k; i++)
    {
        res = res * (n - i + 1) / i;
    }
    return res;
}