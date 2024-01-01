#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    printf("Enter the number of integers you want to find the largest, smallest and average of: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = smallest = sum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        sum += arr[i];
    }

    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);
    printf("Average: %.2f\n", (float) sum / n);

    return 0;
}
