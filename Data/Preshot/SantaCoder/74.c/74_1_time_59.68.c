#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    largest = smallest = sum = count = 0;

    int numbers[n];

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);

        if (i == 0) {
            largest = smallest = numbers[i];
        } else {
            if (numbers[i] > largest) {
                largest = numbers[i];
            }
            if (numbers[i] < smallest) {
                smallest = numbers[i];
            }
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