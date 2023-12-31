List of vulnerabilities detected: 
 Error type: CWE-457 at line: 16. Error message: Uninitialized variable: arr


#include <stdio.h>
int main() {
    int n, largest, smallest, sum, count;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    largest = arr[0];
    smallest = arr[0];
    sum = 0;
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        sum += arr[i];
        count++;
    }
    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %.2f\n", (float) sum / count);
    return 0;
}