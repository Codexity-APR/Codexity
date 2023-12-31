#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("Enter an integer: ");
    scanf("%d", &n);
    largest = smallest = sum = count = n;

    for (int i = 1; i < n; i++) {
        printf("Enter an integer: ");
        scanf("%d", &n);

        if (n > largest) {
            largest = n;
        }

        if (n < smallest) {
            smallest = n;
        }

        sum += n;
        count++;
    }

    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / count);

    return 0;
}