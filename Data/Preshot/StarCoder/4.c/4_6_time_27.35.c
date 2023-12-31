#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int returnModPascal(unsigned long int n,unsigned long int k);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long int n,k;
        scanf("%lu %lu",&n,&k);
        printf("%lu\n",returnModPascal(n,k));
    }
    return 0;
}

unsigned long int returnModPascal(unsigned long int n,unsigned long int k)
{
    unsigned long int i, j, sum = 0, pow_val = 1;
    for(i=0;i<=n;i++)
    {
        pow_val = 1; // set pow_val to 1 in each iteration of i
        for(j=0;j<=i;j++)
        {
            sum += pow_val; // add pow_val to sum
            pow_val *= (i-j); // update pow_val
            pow_val /= (j+1); // update pow_val
        }
    }
    return sum%k;
}