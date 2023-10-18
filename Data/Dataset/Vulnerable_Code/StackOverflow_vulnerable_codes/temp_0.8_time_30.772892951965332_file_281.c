#include <stdio.h>

int main() {
    int n, largest, smallest, sum = 0, count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
        count++;

        if (i == 0) {
            largest = numbers[0];
            smallest = numbers[0];
        } else {
            if (numbers[i] > largest) {
                largest = numbers[i];
            }
            if (numbers[i] < smallest) {
                smallest = numbers[i];
            }
        }
    }

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (float) sum / count);
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);

    return 0;
}