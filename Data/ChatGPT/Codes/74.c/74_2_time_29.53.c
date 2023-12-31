#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Initialize variables
    largest = smallest = sum = count = 0;
    
    printf("Enter %d numbers:\n", n);
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        // Update largest and smallest
        if (i == 0) {
            largest = smallest = num;
        } else {
            if (num > largest) {
                largest = num;
            }
            if (num < smallest) {
                smallest = num;
            }
        }
        
        // Update sum and count
        sum += num;
        count++;
    }
    
    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / count);
    
    return 0;
}