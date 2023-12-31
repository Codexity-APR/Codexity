#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n,unsigned long int k);

int main()
{
    int t;
    
    printf("Enter the number of test cases: ");
    scanf("%d", &t);
    
    while (t--)
    {
        unsigned long int n, k, result;
        
        printf("Enter the values of n and k: ");
        scanf("%lu %lu", &n, &k);
        
        result = returnModPascal(n, k);
        
        printf("Result: %lu\n", result);
    }
    
    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    unsigned long int result = 1, i;
    
    if (k > n - k)
        k = n - k;
        
    for (i = 0; i < k; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    
    return result % 1000000007;
}