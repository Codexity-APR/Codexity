#include <stdio.h>

void arrays()
{
    int i,n,j;
    printf("Enter the size of the arrays:\n");
    scanf("%d",&n);

    int a1[n];
    int a2[n];
    int intersection[n], unions[2*n]; //intersection can have a maximum of n elements and unions can have a maximum of 2*n elements
    printf("Enter elements of the first array:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d",&a1[i]);
    }
    printf("Enter elements of the second array:\n");
    for (j = 0; j < n; j++)
    {
        scanf("%d",&a2[j]);
    }
    int indexs = -1, indexu = -1;
    for (i = 0; i < n; i++) //calculating union
    {
        int flag = 0; //to check if an element in a1 is also present in a2
        for (j = 0; j < n; j++)
        {
            if(a1[i] == a2[j])
            {
                flag = 1; //a1[i] is also present in a2
                break;
            }
        }
        if(flag == 0) //a1[i] not present in a2
        {
            unions[++indexu] = a1[i];
        }
    }
    for (j = 0; j < n; j++)
    {
        unions[++indexu] = a2[j];
    }
    for (i = 0; i < n; i++) //calculating intersection
    {
        for (j = 0; j < n; j++)
        {
            if(a1[i] == a2[j])
            {
                intersection[++indexs] = a1[i];
                break;
            }
        }
    }

    printf("Intersection: ");
    for(i = 0; i <= indexs; i++) //printing intersection
    {
        printf("%d ",intersection[i]);
    }
    printf("\nUnion: ");
    for (j = 0; j <= indexu; j++) //printing union
    {
