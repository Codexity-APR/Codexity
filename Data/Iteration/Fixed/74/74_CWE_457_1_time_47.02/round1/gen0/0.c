#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, largest, smallest, sum, count;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory for arr
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Initialize the variables
    largest = smallest = arr[0];
    sum = count = 0;
    // Find the largest, smallest, and sum of the numbers
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
    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);
    printf("Sum of numbers: %d\n", sum);
    printf("Average of numbers: %.2f\n", (float)sum / count);

    free(arr); // Free the dynamically allocated memory
    return 0;
}