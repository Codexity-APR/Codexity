#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int n, largest, smallest, sum, count;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[MAX_SIZE] = {0}; // Initialize arr with default value 0
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    largest = arr[0];
    smallest = arr[0];
    sum = 0;
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        sum += arr[i];
        count++;
    }
    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %.2f\n", (float) sum / count);
    return 0;
}
```

Please note that I have added the initialization `int arr[MAX_SIZE] = {0}