#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    
    largest = smallest = sum = count = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d integers: ", n);
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if (i == 0) {
            largest = smallest = num;
        }
        
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
    printf("Sum of numbers: %d\n", sum);
    printf("Average of numbers: %.2f\n", (float) sum / count);
    
    return 0;
}