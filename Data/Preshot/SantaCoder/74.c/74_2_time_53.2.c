#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    largest = smallest = sum = 0;

    for (int i = 1; i <= n; i++) {
        int num;
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        if (i == 1) {
            largest = smallest = num;
        } else {
            if (num > largest) {
                largest = num;
            }
            if (num < smallest) {
                smallest = num;
            }
        }
        sum += num;
    }

    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);
    printf("Sum of all numbers: %d\n", sum);

    return 0;
}