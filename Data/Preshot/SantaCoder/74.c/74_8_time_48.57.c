#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    largest = 0;
    smallest = n;
    sum = 0;
    count = 0;

    for (int i = 1; i <= n; i++) {
        if (i > largest) {
            largest = i;
        }
        if (i < smallest) {
            smallest = i;
        }
        sum += i;
        count++;
    }

    printf("largest: %d\n", largest);
    printf("smallest: %d\n", smallest);
    printf("sum: %d\n", sum);
    printf("count: %d\n", count);

    return 0;
}