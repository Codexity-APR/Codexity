#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n,unsigned long int k);

int main()
{
    int t;
    unsigned long int n, k, result;

    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        printf("\nEnter the values of n and k for test case %d: ", i + 1);
        scanf("%lu %lu", &n, &k);
        
        result = returnModPascal(n, k);

        printf("\nThe value of C(%lu, %lu) mod 1000000007 is: %lu\n", n, k, result);
    }

    return 0;
}

unsigned long int returnModPascal(unsigned long int n, unsigned long int k)
{
    unsigned long int result = 1;

    if (k > n - k) {
        k = n - k;
    }

    for (unsigned long int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result % 1000000007;
}