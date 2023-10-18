#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int cnt, int **low, int **high)
{
    int neg_count = 0;
    int pos_count = 0;

    // Count the number of negative and positive numbers
    for(int i = 0; i < cnt; i++)
    {
        if(arr[i] < 0)
        {
            neg_count++;
        }
        else
        {
            pos_count++;
        }
    }

    // Allocate memory for negative and positive arrays
    *low = (int*) malloc(sizeof(int) * neg_count);
    *high = (int*) malloc(sizeof(int) * pos_count);

    // Fill the negative and positive arrays
    int neg_index = 0;
    int pos_index = 0;
    for(int i = 0; i < cnt; i++)
    {
        if(arr[i] < 0)
        {
            (*low)[neg_index++] = arr[i];
        }
        else
        {
            (*high)[pos_index++] = arr[i];
        }
    }
}

int main(void)
{
    int array[] = {1, -1, 2, 3, 4, -5, 6};
    int cnt = sizeof(array)/sizeof(array[0]);
    int *neg, *pos;
    int **low = &neg;
    int **high = &pos;

    neg = (int*) malloc(sizeof(int) * 2);
    pos = (int*) malloc(sizeof(int) * 5);

    sort(array, cnt, low, high);

    printf("Positive Numbers:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%3d\n", pos[i]);
    }

    printf("\nNegative Numbers:\n");
    for(int i = 0; i < 2; i++)
    {
        printf("%3d\n", neg[i]);
    }

    free(neg);
    free(pos);

    return 0;
}