#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;

    printf("Enter the number of elements to be entered: ");
    scanf("%d", &n);

    int arr[n];
    largest = smallest = sum = 0;

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    printf("The largest number is %d\n", largest);
    printf("The smallest number is %d\n", smallest);
    printf("The sum of all the numbers is %d\n", sum);

    return 0;
}