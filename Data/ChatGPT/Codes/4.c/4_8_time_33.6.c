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
        
        unsigned long int modPascal = returnModPascal(n, k);
        
        printf("Modular Pascal value: %lu\n", modPascal);
        
        t--;
    }
    
    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    unsigned long int modPascal = 1;
    
    if (k > n - k)
        k = n - k;
    
    for (unsigned long int i = 0; i < k; i++)
    {
        modPascal *= (n - i);
        modPascal /= (i + 1);
    }
    
    return modPascal;
}