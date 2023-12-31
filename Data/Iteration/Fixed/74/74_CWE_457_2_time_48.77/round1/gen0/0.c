#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int numbers[n] = {0}; // Initialize the numbers array with default value 0
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    largest = numbers[0];
    smallest = numbers[0];
    sum = numbers[0];
    count = 1;
    for (int i = 1; i < n; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
        sum += numbers[i];
        count++;
    }
    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);
    printf("Sum of numbers: %d\n", sum);
    printf("Average of numbers: %.2f\n", (float) sum / count);
    return 0;
}