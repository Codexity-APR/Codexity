#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n,unsigned long int k);

int main()
{
    int t;
    unsigned long int n, k, result;
    
    scanf("%d", &t);
    
    for(int i=0; i<t; i++)
    {
        scanf("%lu %lu", &n, &k);
        result = returnModPascal(n,k);
        printf("%lu\n", result);
    }
    
    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    // Your code for returning the modulo of the Pascal's triangle value
    // with respect to a prime number goes here
}