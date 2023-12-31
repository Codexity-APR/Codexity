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
    unsigned long int i,j,sum=0;
    for(i=0;i<=n;i++)
    {
        unsigned long int term = 1;
        for(j=0;j<=i;j++)
        {
            term = term * (n-j)/(j+1);
        }
        sum += term;
    }
    return sum%k;
}