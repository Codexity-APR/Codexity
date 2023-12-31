#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter integer %d: ", i+1);
        scanf("%d", &arr[i]);
        
        if (i == 0) {
            largest = smallest = arr[i];
        }
        else {
            if (arr[i] > largest) {
                largest = arr[i];
            }
            if (arr[i] < smallest) {
                smallest = arr[i];
            }
        }
        
        sum += arr[i];
        count++;
    }
    
    printf("The largest number is %d\n", largest);
    printf("The smallest number is %d\n", smallest);
    printf("The sum of the integers is %d\n", sum);
    printf("The average of the integers is %.2f\n", (float)sum/count);
    
    return 0;
}