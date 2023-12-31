#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];
    largest = smallest = 0;
    sum = count = 0;

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i == 0) {
            largest = smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        sum += arr[i];
        count++;
    }

    printf("The largest number is %d.\n", largest);
    printf("The smallest number is %d.\n", smallest);
    printf("The sum of all the numbers is %d.\n", sum);
    printf("The average of all the numbers is %.2f.\n", (float) sum / count);

    return 0;
}