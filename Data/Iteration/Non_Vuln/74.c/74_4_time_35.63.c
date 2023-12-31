#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Input validation
    if (n <= 0) {
        printf("Invalid input! The number of elements must be greater than 0.\n");
        return 0;
    }
    
    printf("Enter %d integers:\n", n);
    
    // Initialize variables
    sum = 0;
    count = 0;
    
    // Read the first element and initialize largest and smallest
    scanf("%d", &largest);
    smallest = largest;
    sum += largest;
    count++;
    
    // Read the remaining elements
    for (int i = 1; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        // Update largest and smallest
        if (num > largest) {
            largest = num;
        }
        if (num < smallest) {
            smallest = num;
        }
        
        sum += num;
        count++;
    }
    
    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);
    printf("Sum of all numbers: %d\n", sum);
    printf("Average of all numbers: %.2f\n", (float) sum / count);
    
    return 0;
}