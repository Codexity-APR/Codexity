#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    largest = smallest = sum = arr[0];
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
    
    printf("The average is %f\n", (float)sum / count);
    printf("The largest is %d\n", largest);
    printf("The smallest is %d\n", smallest);
    
    return 0;
}