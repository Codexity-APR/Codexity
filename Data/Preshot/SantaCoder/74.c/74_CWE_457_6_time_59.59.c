#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the %d integers: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];
    smallest = arr[0];
    sum = arr[0];
    count = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
        sum += arr[i];
        count++;
    }

    printf("Largest integer is %d\n", largest);
    printf("Smallest integer is %d\n", smallest);
    printf("Sum of integers is %d\n", sum);
    printf("Average of integers is %.2f\n", (float)sum/count);

    return 0;
}