#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;

    printf("Enter the number of integers to compare: ");
    scanf("%d", &n);

    int num[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    largest = smallest = sum = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] > largest) {
            largest = num[i];
        }
        if (num[i] < smallest) {
            smallest = num[i];
        }
        sum += num[i];
    }

    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);
    printf("Sum of numbers: %d\n", sum);

    float average = (float)sum / n;
    printf("Average of numbers: %.2f\n", average);

    return 0;
}