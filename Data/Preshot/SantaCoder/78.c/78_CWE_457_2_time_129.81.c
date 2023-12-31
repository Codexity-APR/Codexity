#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void arrays()
{
    int n;
    printf("Enter the size of the arrays:\n");
    scanf("%d",&n);

    int a1[n];
    int a2[n];
    int intersection[n], unions[2*n]; //intersection can have a maximum of n elements and unions can have a maximum of 2*n elements

    printf("Enter elements of the first array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a1[i]);
    }

    printf("Enter elements of the second array:\n");
    for (int j = 0; j < n; j++)
    {
        scanf("%d",&a2[j]);
    }

    int indexs = -1, indexu = -1;

    for (int i = 0; i < n; i++) //calculating union
    {
        int flag = 0; //to check if an element in a1 is also present in a2
        for (int j = 0; j < n; j++)
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

    for (int j = 0; j < n; j++)
    {
        unions[++indexu] = a2[j];
    }

    for (int i = 0; i < n; i++) //calculating intersection
    {
        for (int j = 0; j < n; j++)
        {
            if(a1[i] == a2[j])
            {
                intersection[++indexs] = a1[i];
                break;
            }
        }
    }

    printf("Intersection: ");
    for(int i = 0; i <= indexs; i++) //printing intersection
    {
        printf("%d ",intersection[i]);
    }

    printf("\nUnion: ");
    for (int j = 0; j <= indexu; j++) //printing union
    {
        printf("%d ",unions[j]);
    }
}

int main()
{
    arrays();
    return 0;
}