#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);

    // reading n elements into array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = smallest = sum = count = arr[0]; // initializing largest, smallest, sum and count with first element of array
    for (int i = 1; i < n; i++) {
        int num = arr[i];
        if (num > largest) {
            largest = num;
        }
        if (num < smallest) {
            smallest = num;
        }
        sum += num;
        count++;
    }

    printf("The average is %.2f\n", (float)sum / count);
    printf("The largest is %d\n", largest);
    printf("The smallest is %d\n", smallest);
    return 0;
}