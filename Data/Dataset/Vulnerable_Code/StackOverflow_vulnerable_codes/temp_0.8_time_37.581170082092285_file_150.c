#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n, unsigned long int k);

int main()
{
    int t;
    
    printf("Enter the number of test cases: ");
    scanf("%d", &t);
    
    while (t > 0) {
        unsigned long int n, k, result;
        
        printf("Enter the values of n and k: ");
        scanf("%lu %lu", &n, &k);
        
        result = returnModPascal(n, k);
        
        printf("The result is %lu\n", result);
        
        t--;
    }
    
    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    if (k == 0 || k == n) {
        return 1;
    }
    
    return returnModPascal(n - 1, k - 1) + returnModPascal(n - 1, k);
}