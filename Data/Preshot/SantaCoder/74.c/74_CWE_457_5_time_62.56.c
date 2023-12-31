#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];
    smallest = arr[0];
    sum = arr[0];
    count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        sum += arr[i];
        count++;
    }

    float average = sum / (float) count;

    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %.2f\n", average);

    return 0;
}