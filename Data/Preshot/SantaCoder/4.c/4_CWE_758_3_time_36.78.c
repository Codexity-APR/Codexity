#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n,unsigned long int k);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        unsigned long int n, k;
        scanf("%lu %lu", &n, &k);
        unsigned long int ans = returnModPascal(n, k);
        printf("%lu\n", ans);
    }
    return 0;
}

unsigned long int returnModPascal(unsigned long int n,unsigned long int k)
{
    // your code here
}