#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n,unsigned long int k);

int main()
{
    int t;
    scanf("%d", &t); // read the number of test cases from input
    while (t--)
    {
        unsigned long int n, k;
        scanf("%lu %lu", &n, &k); // read n and k from input
        printf("%lu\n", returnModPascal(n, k)); // print the output of returnModPascal function
    }
    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    unsigned long int ans = 1;
    if (k > n - k) 
        k = n - k;
    for (unsigned long int i = 0; i < k; ++i) 
    {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans % 1000000007;
}