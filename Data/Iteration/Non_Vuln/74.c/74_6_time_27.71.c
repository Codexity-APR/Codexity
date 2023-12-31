#include <stdio.h>

int main() {
    int n, largest, smallest, sum, count;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    largest = smallest = sum = count = 0;
    
    printf("Enter the elements:\n");
    
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
    
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / count);
    
    return 0;
}