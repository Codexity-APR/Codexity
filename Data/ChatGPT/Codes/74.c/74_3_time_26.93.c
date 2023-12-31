#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
  
    printf("Enter the number of elements: ");
    scanf("%d", &n);
  
    printf("Enter the numbers: ");
  
    // Initialize variables
    scanf("%d", &n);
    largest = smallest = sum = count = n;
  
    // Loop through the remaining elements
    for (int i = 1; i < n; i++) {
        scanf("%d", &n);
        
        // Update largest and smallest
        if (n > largest) {
            largest = n;
        }
        if (n < smallest) {
            smallest = n;
        }
        
        // Update sum and count
        sum += n;
        count++;
    }
  
    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / count);
  
    return 0;
}